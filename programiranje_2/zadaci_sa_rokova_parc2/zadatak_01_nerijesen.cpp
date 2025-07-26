#include <iostream>
#include <iomanip>
#include <cstdint>
#include <list>
#include <utility>
#include <atomic>
#include <algorithm>

class MACAdresa {
    uint8_t adresa[6] = {0, 0, 0, 0, 0, 0}; // Inicijalizacija adrese na nulu
public:
    MACAdresa(){}

    template<typename T>
    MACAdresa(const T& kolekcija) {
        int i(0);
        for (auto &element : kolekcija) 
            if (i < 6) // Ograničavamo na 6 elemenata
                adresa[i++] = element;
            else 
                break;
        for (; i < 6; ++i)
            adresa[i] = 0; // Popuni nulama ako kolekcija ima manje od 6 elemenata
    }

    template<std::size_t N>
    MACAdresa(const uint8_t (&niz)[N]) {
        int i = 0;
        for (; i < 6 && i < N; ++i)
            adresa[i] = niz[i];
        for (; i < 6; ++i)
            adresa[i] = 0; // Popuni nulama ako niz ima manje od 6 elemenata
    }

    bool operator==(const MACAdresa& other) const {
        for (int i = 0; i < 6; ++i)
            if (adresa[i] != other.adresa[i])
                return false;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& ispis, const MACAdresa& mac) {
        ispis << std::hex << std::setfill('0'); // Postavljanje formata ispisa u heksadecimalni
        for (int i = 0; i < 6; ++i) {
            ispis << std::setw(2) << static_cast<int>(mac.adresa[i]);
            if (i != 5)
                ispis << ":";
        }
        ispis << std::dec;
        return ispis;
    }
};

class Okvir {
    MACAdresa izvorna;
    MACAdresa destinaciona;
    uint8_t* sadrzaj;
    std::size_t n;

    // Zabrana kopiranja
    Okvir(const Okvir&) = delete;
    Okvir& operator=(const Okvir&) = delete;

public:
    Okvir(const MACAdresa& izvor, const MACAdresa& destinacija, const uint8_t* podaci, std::size_t velicina)
        : izvorna(izvor), destinaciona(destinacija), n(velicina)
    {
        sadrzaj = new uint8_t[n];
        for (std::size_t i = 0; i < n; ++i)
            sadrzaj[i] = podaci[i];
    }

    ~Okvir() {
        delete[] sadrzaj;
    }

    // Dohvatanje atributa
    const MACAdresa& getIzvorna() const { return izvorna; }
    const MACAdresa& getDestinaciona() const { return destinaciona; }
    const uint8_t* getSadrzaj() const { return sadrzaj; }
    std::size_t getVelicina() const { return n; }

    friend std::ostream& operator<<(std::ostream& ispis, const Okvir& okvir){
        ispis << "Frame[src: " << okvir.izvorna 
              << ", dst: " << okvir.destinaciona 
              << ", content: ";
              for (std::size_t i = 0; i < okvir.n; ++i) {
                  ispis << okvir.sadrzaj[i];
              }
        ispis << "]";
        return ispis;
    }
};

class MrezniUredjaj; // Predeklaracija

class Sucelje {
    MACAdresa adresa;
    Sucelje* povezano_sucelje = nullptr;
    MrezniUredjaj* vlasnik = nullptr;

    // Zabrana kopiranja
    Sucelje(const Sucelje&) = delete;
    Sucelje& operator=(const Sucelje&) = delete;

public:
    explicit Sucelje(MrezniUredjaj* vlasnik) : vlasnik(vlasnik) {}

    void setAdresa(const MACAdresa& adr) { adresa = adr; }
    const MACAdresa& getAdresa() const { return adresa; }

    void setPovezanoSucelje(Sucelje* drugo) { povezano_sucelje = drugo; }
    Sucelje* getPovezanoSucelje() const { return povezano_sucelje; }

    MrezniUredjaj* getVlasnik() const { return vlasnik; }

    void prihvati(const Okvir& okvir);

    void posalji(const Okvir& okvir) {
        if (povezano_sucelje)
            povezano_sucelje->prihvati(okvir);
    }
};

class MrezniUredjaj {
protected:
    Sucelje** sucelja;
    std::size_t broj_sucelja;
public:
    MrezniUredjaj(std::size_t broj) : broj_sucelja(broj) {
        sucelja = new Sucelje*[broj_sucelja];
        for (std::size_t i = 0; i < broj_sucelja; ++i)
            sucelja[i] = new Sucelje(this);
    }
    virtual ~MrezniUredjaj() {
        for (std::size_t i = 0; i < broj_sucelja; ++i)
            delete sucelja[i];
        delete[] sucelja;
    }

    std::size_t getBrojSucelja() const { return broj_sucelja; }
    Sucelje* getSucelje(std::size_t i) const { return (i < broj_sucelja) ? sucelja[i] : nullptr; }

    // Dohvati slobodno (nepovezano) sucelje, ili nullptr ako nema
    Sucelje* uzmiSlobodan() const {
        for (std::size_t i = 0; i < broj_sucelja; ++i)
            if (sucelja[i]->getPovezanoSucelje() == nullptr)
                return sucelja[i];
        return nullptr;
    }

    // Virtuelna metoda za obradu okvira
    virtual void obrada(Sucelje* sucelje, const Okvir& okvir) = 0;
};


// Hab: prosljeđuje okvir na sve interfejse osim na onaj preko kojeg je primljen
class Hab : public MrezniUredjaj {
public:
    Hab(std::size_t broj) : MrezniUredjaj(broj) {}

    void obrada(Sucelje* sucelje, const Okvir& okvir) override {
        for (std::size_t i = 0; i < broj_sucelja; ++i) {
            if (sucelja[i] != sucelje) {
                sucelja[i]->posalji(okvir);
            }
        }
    }
};

// Svic: vodi tabelu (adresa, interfejs), ažurira je i prosljeđuje okvir na osnovu nje
class Svic : public MrezniUredjaj {
    using Par = std::pair<MACAdresa, Sucelje*>;
    std::list<Par> tabela;
public:
    Svic(std::size_t broj) : MrezniUredjaj(broj) {}

    void obrada(Sucelje* sucelje, const Okvir& okvir) override {
        // Ažuriraj tabelu: ako postoji adresa, ažuriraj interfejs; ako ne, dodaj novi unos
        auto it = std::find_if(tabela.begin(), tabela.end(),
            [&](const Par& p) { return p.first == okvir.getIzvorna(); });
        if (it != tabela.end()) {
            it->second = sucelje;
        } else {
            tabela.emplace_back(okvir.getIzvorna(), sucelje);
        }

        // Pronađi interfejs za destinacionu adresu
        auto it2 = std::find_if(tabela.begin(), tabela.end(),
            [&](const Par& p) { return p.first == okvir.getDestinaciona(); });
        if (it2 != tabela.end() && it2->second != sucelje) {
            it2->second->posalji(okvir);
        }
        // Ako ne postoji destinaciona adresa u tabeli, okvir se ne prosljeđuje
    }
};

// Host: ima jedinstveni id, može slati okvire i ispisuje obradu okvira
class Host : public MrezniUredjaj {
    static std::atomic<int> id_gen;
    int id;
public:
    Host() : MrezniUredjaj(1), id(++id_gen) {}

    // Host ima samo jedno sucelje (indeks 0)
    void posaljiOkvir(const MACAdresa& dst, const uint8_t* podaci, std::size_t velicina) {
        Okvir okvir(sucelja[0]->getAdresa(), dst, podaci, velicina);
        sucelja[0]->posalji(okvir);
    }

    void obrada(Sucelje* sucelje, const Okvir& okvir) override {
        if (okvir.getDestinaciona() == sucelje->getAdresa()) {
            std::cout << "Host:" << id << "-" << okvir << " allow" << std::endl;
        } else {
            std::cout << "Host:" << id << "-" << okvir << " deny" << std::endl;
        }
    }

    int getId() const { return id; }
};

std::atomic<int> Host::id_gen{0};

int main() {
    try{
        unsigned char macNizA[6] = {1, 1, 1, 1, 1, 1};
        unsigned char macNizB[6] = {2, 2, 2, 2, 2, 2};
        MACAdresa macAdrA(macNizA);
        MACAdresa macAdrB(macNizB);
        Host *a = new Host(1), *b = new Host(1);
        Hab *hab = new Hab(2);
        Sucelje *habInt1 = hab->uzmiSlobodan();
        Sucelje *aInt = a->uzmiSlobodan();
        aInt->postMAC(macAdrA);
        aInt->postSusjeda(habInt1);
        habInt1->postSusjeda(aInt);
        Sucelje *habInt2 = hab->uzmiSlobodan();
        Sucelje *bInt = b->dohvatiSlobodan();
        bInt->postMAC(macAdrB);
        bInt->postSusjeda(habInt2);
        habInt2->postSusjeda(bInt);
        unsigned char sadrzaj[3] = {'m', 's', 'g'};
        Okvir okvir(macAdrA, macAdrB, sadrzaj, 3);
        a->posaljiOkvir(okvir);
        delete a;
        delete b;
        delete hab;

    }
    
    return 0;
}
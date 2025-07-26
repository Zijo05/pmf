#include <iostream>
#include <vector>

class Razlomak {
    int brojnik, nazivnik;
    static int provjeriNazivnik(int n) {
        if(n == 0)
            throw std::domain_error("Razlomak nije u ispravnom obliku!");
        return n;
    }
public:
    Razlomak(int b, int n = 1) : brojnik(b), nazivnik(provjeriNazivnik(n)) {}

    int getBrojnik() const {return brojnik;}

    int getNazivnik() const {return nazivnik;}

    friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2) {
        return Razlomak(r1.brojnik * r2.nazivnik + r2.brojnik * r1.nazivnik
                        , r1.nazivnik * r2.nazivnik);
    }
    
    friend Razlomak operator*(const Razlomak& r1, const Razlomak& r2) {
        return Razlomak(r1.brojnik * r2.brojnik, r1.nazivnik * r2.nazivnik);
    }

    friend bool operator>(const Razlomak& r1, const Razlomak& r2) {
        return r1.brojnik * r2.nazivnik > r2.brojnik * r1.nazivnik;
    }

    friend bool operator==(const Razlomak& r1, const Razlomak& r2) {
        return r1.brojnik * r2.nazivnik == r2.brojnik * r1.nazivnik;
    }

    friend bool operator!=(const Razlomak& r1, const Razlomak& r2) {
        return r1.brojnik * r2.nazivnik != r2.brojnik * r1.nazivnik;
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Razlomak& r) {
        ispis << r.brojnik << "/" << r.nazivnik;
        return ispis;
    }
};  


class MuzickiZnak {
    Razlomak trajanje;
public:
    explicit MuzickiZnak(const Razlomak& r) : trajanje(r) {}

    virtual ~MuzickiZnak() {};

    Razlomak getTrajanje() const {return trajanje;}

    friend Razlomak operator+(const MuzickiZnak& mz1, const MuzickiZnak& mz2) {
        return mz1.trajanje + mz2.trajanje;
    }

    operator Razlomak() const {return trajanje;}

    virtual std::string opisZnaka() const = 0;

    friend std::ostream& operator<<(std::ostream& ispis, const MuzickiZnak& mz) {
        ispis << mz.opisZnaka() << "(" << mz.trajanje << ")";
        return ispis;
    }
};

enum Visina  {DO, RE, MI, FA, SOL, LA, SI};

class Nota : public MuzickiZnak {
    int oktava;
    Visina visina;
public:
    Nota(int o, Visina v, const Razlomak& r) : MuzickiZnak(r), visina(v), oktava(o) {}

    friend Nota& operator<<=(Nota& n, int p) {
        n.oktava -= p;
        return n;
    }

    friend Nota& operator>>=(Nota& n, int p) {
        n.oktava += p;
        return n;
    }

    std::string opisZnaka() const override {
        static const std::string imenaVisina[] = {"DO", "RE", "MI", "FA", "SOL", "LA", "SI"};
        return imenaVisina[visina];
    }
};

class Pauza : public MuzickiZnak {
public:
    Pauza(const Razlomak& r) : MuzickiZnak(r) {}

    std::string opisZnaka() const override {
        return "_";
    }
};

class Takt {
    std::vector<MuzickiZnak*> muzicki_znakovi;
    Razlomak maksimalno_trajanje;
    bool kompletiran = false;

    Razlomak sumaTrajanjaMZ() const{
        Razlomak suma(0);
        for(const auto& mz : muzicki_znakovi)
            suma = suma + mz->getTrajanje();
        return suma;
    }
public:
    Takt(const Razlomak& r): maksimalno_trajanje(r) {}

    Takt(const Takt& t) = delete;

    const Razlomak& getMaxTrajanje() const {return maksimalno_trajanje;}

    Takt& dodaj(MuzickiZnak* mz) {
        if(mz->getTrajanje() > maksimalno_trajanje)
            throw std::invalid_argument("Prekoracenje trjanja takta");
        else if(kompletiran)
            throw std::invalid_argument("Takt je kompletiran");
        else{
            muzicki_znakovi.push_back(mz);
        }
        return *this;
    }

    bool jelNepotpun() const {return maksimalno_trajanje > sumaTrajanjaMZ();}

    void zavrsi() {kompletiran = true;}

    bool jelTaktZavrsen() const {return kompletiran;}

    friend std::ostream& operator<<(std::ostream& ispis, const Takt& t) {
        for(const auto& mz : t.muzicki_znakovi)
            ispis << *mz << " ";
        ispis << "|";
        return ispis;
    }
};

class Kompozicija {
    std::vector<Takt*> taktovi;
public:
    Kompozicija() = default;
    Kompozicija(const Kompozicija& k) = delete;

    Kompozicija& dodaj(Takt& t) {
        if(!(t.jelTaktZavrsen()))
            throw std::invalid_argument("Takt nije zavrsen");
        if(taktovi.size() != 0){
            if(t.getMaxTrajanje() != taktovi.at(0)->getMaxTrajanje())
                throw std::invalid_argument("Nejednaka duzina taktova");
            
            for (int i = 1; i < taktovi.size(); ++i)
                if (taktovi[i]->jelNepotpun())
                    throw std::invalid_argument("Nejednaka duzina taktova");
        }
        taktovi.push_back(&t);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Kompozicija& k) {
        for(const auto& t : k.taktovi) 
            ispis << *t << " ";
        return ispis;
    }
};

int main() {
    try{
        std::vector<Nota*> note;
        std::vector<Pauza*> pauze;

        int BN,BP; //BN-broj nota, BP-broj pauza;
        std::cin >>BN;

        for(int i(0); i<BN; i++) {
            int O,V,B,N; //O-oktava, V-visina, B-brojnik, N-nazivnik
            std::cin >>O>>V>>B>>N;
            note.emplace_back(new Nota(O,static_cast<Visina>(V),Razlomak(B,N)));
        }

        std::cin >>BP;

        for (int i(0); i < BP; i++) {
            int B, N; std::cin>>B>>N;//B-brojnik, N-nazivnik
            pauze.emplace_back(new Pauza(Razlomak(B,N)));
        }

        Razlomak osm(1, 8), cet(1, 4), pol(1, 2);
        Takt t1(pol), t2(pol), t3(pol);

        if (!note.empty()) t1.dodaj(note[0]).zavrsi();
        if (note.size() > 1) t2.dodaj(note[1]).zavrsi();
        if (note.size() > 2) t3.dodaj(note[2]);
        if (!pauze.empty()) t3.dodaj(pauze[0]);
        if (pauze.size()>1) t3.dodaj(pauze[1]);
        if (note.size() > 3)t3.dodaj(note[3]).zavrsi();

        Kompozicija k;
        k.dodaj(t1).dodaj(t2).dodaj(t3);

        std::cout << k;
    }
    catch (const std::exception& e) { std::cout << e.what(); }

    return 0;
}
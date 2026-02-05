#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

list<string> vrati_indexe() {
    list<string> l;

    l.push_back("6133/M");
    l.push_back("257/IT-21");
    l.push_back("6174/M");
    l.push_back("199/IT-20");
    l.push_back("270/IT-21");
    l.push_back("5863/M");
    l.push_back("6073/M");
    l.push_back("341/IT-22");
    l.push_back("6061/M");
    l.push_back("6155/M");
    l.push_back("6116/M");
    l.push_back("406/IT-23");
    l.push_back("323/IT-22");
    l.push_back("131/IT-19");
    l.push_back("404/IT-23");
    l.push_back("5924/M");
    l.push_back("6067/M");
    l.push_back("6176/M");
    l.push_back("121/IT-19");
    l.push_back("6014/M");
    l.push_back("262/IT-21");
    l.push_back("6021/M");
    l.push_back("5864/M");
    l.push_back("428/IT-23");
    l.push_back("6/IT-18");
    l.push_back("5696/M");
    l.push_back("5749/M");
    l.push_back("6044/M");
    l.push_back("434/IT-23");
    l.push_back("432/IT-23");
    l.push_back("241/IT-20");
    l.push_back("448/IT-23");
    l.push_back("5942/M");
    l.push_back("5792/M");
    l.push_back("6099/M");
    l.push_back("5767/M");
    l.push_back("5922/M");
    l.push_back("5769/M");
    l.push_back("443/IT-23");
    l.push_back("6015/M");
    l.push_back("5526/M");
    l.push_back("450/IT-23");
    l.push_back("6119/M");
    l.push_back("6173/M");
    l.push_back("6034/M");
    l.push_back("423/IT-23");
    l.push_back("5880/M");
    l.push_back("269/IT-21");
    l.push_back("338/IT-22");
    l.push_back("5912/M");
    l.push_back("316/IT-21");
    l.push_back("5758/M");
    l.push_back("5950/M");
    l.push_back("253/IT-21");
    l.push_back("6140/M");
    l.push_back("139/IT-19");
    l.push_back("6013/M");
    l.push_back("6137/M");
    l.push_back("5873/M");
    l.push_back("6089/M");
    l.push_back("418/IT-23");
    l.push_back("350/IT-22");
    l.push_back("6016/M");
    l.push_back("6203/M");
    l.push_back("335/IT-22");
    l.push_back("5862/M");
    l.push_back("303/IT-21");
    l.push_back("391/IT-23");
    l.push_back("6159/M");
    l.push_back("5668/M");
    l.push_back("287/IT-21");

    return l;
}

int prvi_sljedeci_prost_broj(int p) {
    auto r = p;
    while (true) {
        bool prost = true;
        auto korijen = int(sqrt(r));
        for (int i = 2; i <= korijen; i++) {
            if (r % i == 0) {
                prost = false;
                break;
            }
        }
        if (prost)
            return r;

        r += 2;
    }
}

template<typename K, typename V, class H>
class HashTablica {

private:
    enum class Status { S_SLOBODAN, S_ZAUZET, S_OBRISAN };

    class Element {
    public:
        K m_kljuc;
        V m_vrijednost;
        Status m_status;

        Element(): m_status(Status::S_SLOBODAN) {}
    };

    vector<Element> m_tablica;
    size_t m_broj_zauzetih;
    size_t m_broj_alociranih;
    H m_hasher;
    size_t m_broj_poredjenja;
public:
    HashTablica() {
        m_hasher = H{};
        m_tablica.resize(151);
        m_broj_alociranih = 151;
        m_broj_zauzetih = 0;

        m_broj_poredjenja = 0;
    }

    void Dodaj(K kljuc, V vrijednost) {
        if (m_broj_zauzetih / m_broj_alociranih > 0.6) {
            // moramo da radimo rehash
            Rehash();
        }

        auto h = m_hasher(kljuc) % m_broj_alociranih;
        // ideja je da uvijek ima mjesta!
        while (true) {
            m_broj_poredjenja++;
            if (m_tablica[h].m_status == Status::S_ZAUZET) {
                h = (h+1) % m_broj_alociranih;
                continue;
            }

            // ako bih vodio statistiku, smanjiti broj obrisanih

            m_tablica[h].m_status = Status::S_ZAUZET;
            m_tablica[h].m_kljuc = kljuc;
            m_tablica[h].m_vrijednost = vrijednost;
            m_broj_zauzetih++;

            return;
        }
    }

    void Rehash() {
        std::cout << "Radim rehash\n";
        auto kopija = m_tablica;
        auto novi_broj = prvi_sljedeci_prost_broj(2*m_broj_alociranih+1);
        std::cout << novi_broj << "\n";

        m_tablica = vector<Element>(novi_broj); 
        m_broj_alociranih = novi_broj;
        m_broj_zauzetih = 0;
        m_broj_poredjenja = 0;

        for (auto &x: kopija) {
            if (x.m_status == Status::S_ZAUZET)
                Dodaj(x.m_kljuc, x.m_vrijednost);
        }
    }

    void Obrisi(K kljuc) {
        auto h = m_hasher(kljuc) % m_broj_alociranih;
        while (true) {
            if (m_tablica[h].m_status == Status::S_SLOBODAN) {
                throw std::runtime_error("Kljuc ne postoji");
            }

            if (m_tablica[h].m_status == Status::S_ZAUZET &&
                m_tablica[h].m_kljuc == kljuc) {

                // nasli smo nas element
                m_tablica[h].m_status = Status::S_OBRISAN;
                // mogu, ali i nemoram "anulirati" m_kljuc i m_vrijednost
                m_broj_zauzetih--;
                // eventualno, povecati broj obrisanih
                return;
            }

            h = (h+1) % m_broj_alociranih;
        }
    }

    V Nadji(K kljuc) {
        auto h = m_hasher(kljuc) % m_broj_alociranih;
        while (true) {
            if (m_tablica[h].m_status == Status::S_SLOBODAN) {
                throw std::runtime_error("Kljuc ne postoji");
            }

            m_broj_poredjenja++;
            if (m_tablica[h].m_status == Status::S_ZAUZET &&
                m_tablica[h].m_kljuc == kljuc) {

                // nasli smo nas element
                return m_tablica[h].m_vrijednost;
            }

            h = (h+1) % m_broj_alociranih;
        }        
    }

    size_t MojHash(string s) {
        return m_hasher(s);
    }

    void Test() {
        std::cout << ">";
        for (auto &e : m_tablica) {
            if (e.m_status == Status::S_SLOBODAN)
                std::cout << " ";
            else if (e.m_status == Status::S_ZAUZET)
                std::cout << "*";
            else //
                std::cout << "#";
        }
        std::cout << "<";
        std::cout << std::endl;
        std::cout << "Broj poredjenja: " << m_broj_poredjenja << "\n";
    }

    void ResetujStatistiku() {
        m_broj_poredjenja = 0;
    }
};

class MojHasher {
public:
    size_t operator()(string s) {
        int p1 = 37; // 1000000007;
        int p2 = 151; // 1000000009;

        size_t r = 0;
        for (auto c: s) 
            r = (r * p1 + c - 32) % p2;
            // r = (r + c) % p2;
        
        return r;        
    }
};

int main() {
    HashTablica<string, float, MojHasher> h;

    int p = 0.0;
    for (auto broj_indexa: vrati_indexe()) {
        h.Dodaj(broj_indexa, ++p);
    }

    h.Test();

    std::cout <<h.Nadji("6067/M") << "\n";
    std::cout << "-------------------\n";

    h.ResetujStatistiku();

    for (auto broj_indexa: vrati_indexe()) {
        auto v = h.Nadji(broj_indexa);
    }

    h.Test();

    // std::cout <<h.Nadji("6067/M") << "\n";

    return 0;
}
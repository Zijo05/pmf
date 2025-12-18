/* IMPLEMENTACIJA LISTE */

#include <iostream>

template <typename T>
class Cvor
{
public:
    T m_vrijednost;   // Vrijednost
    Cvor *m_sljedeci; // Pokazivac na sljedeci cvor

    Cvor(T vrijednost) : m_vrijednost(vrijednost), m_sljedeci(nullptr) {}
    ~Cvor() { /* m_sljedeci = nullptr; */ }
};

template <typename T>
class Iterator
{
    Cvor<T> *m_cvor;

public:
    Iterator(Cvor<T> *cvor) : m_cvor(cvor) {}
    Iterator &operator++()
    {
        if (m_cvor != nullptr)
            m_cvor = m_cvor->m_sljedeci;
        return *this;
    }

    T &operator*()
    {
        return m_cvor->m_vrijednost;
    }

    bool operator!=(Iterator &desni)
    {
        // lijeva strana nam je this
        return m_cvor != desni.m_cvor;
    }
};

template <typename T>
class Lista
{
    Cvor<T> *m_glava;

public:
    Lista() : m_glava(nullptr) {}
    ~Lista()
    {
        auto pocetak = m_glava;
        while (pocetak != nullptr)
        {
            auto za_brisanje = pocetak;
            pocetak = pocetak->m_sljedeci;
            delete za_brisanje;
        }
    }

    void dodaj_pocetak(const T vrijednost) // Dodaj na pocetak
    {
        auto cvor = new Cvor(vrijednost);
        cvor->m_sljedeci = m_glava;
        m_glava = cvor;
    }

    void dodaj_kraj(const T vrijednost)
    {
        auto novi_cvor = new Cvor(vrijednost);

        if (m_glava == nullptr)
        {
            m_glava = novi_cvor;
        }
        else
        {
            auto tekuci = m_glava;
            while (tekuci->m_sljedeci != nullptr)
                tekuci = tekuci->m_sljedeci;

            // Ovdje tekuci pokazuje na posljedni cvor liste
            tekuci->m_sljedeci = novi_cvor;
        }
    }

    void dodaj_kraj_v2(const T vrijednost)
    {
        auto novi_cvor = new Cvor(vrijednost);
        auto pokazivac_na_tekuci = &m_glava;
        auto tekuci = m_glava;

        while (tekuci != nullptr)
        {
            pokazivac_na_tekuci = &tekuci->m_sljedeci;
            tekuci = tekuci->m_sljedeci;
        }

        *pokazivac_na_tekuci = novi_cvor;
    }

    void obrisi(const T vrijednost)
    {
        auto tekuci = m_glava;
        auto prethodni = &m_glava;
        while (tekuci != nullptr)
        {
            if (tekuci->m_vrijednost == vrijednost)
            {
                *prethodni = tekuci->m_sljedeci;
                delete tekuci;
                return;
            }
            prethodni = &tekuci->m_sljedeci;
            tekuci = tekuci->m_sljedeci;
        }

        throw std::invalid_argument("Ne postoji takav element!");
    }

    void obrisi2(const T vrijednost)
    {
        auto tekuci = m_glava;
        Cvor<T> *prethodni = nullptr;

        while (tekuci != nullptr)
        {
            if (tekuci->m_vrijednost == vrijednost)
            {
                if (prethodni == nullptr)
                    m_glava = tekuci->m_sljedeci;
                else
                    prethodni->m_sljedeci = tekuci->m_sljedeci;

                delete tekuci;
                return;
            }

            prethodni = tekuci;
            tekuci = tekuci->m_sljedeci;
        }

        throw std::invalid_argument("Ne postoji takav element!");
    }

    void ispisi_primitivno()
    {
        auto pocetak = m_glava;
        while (pocetak != nullptr)
        {
            std::cout << pocetak->m_vrijednost << " ";
            pocetak = pocetak->m_sljedeci;
        }
    }

    Iterator<T> begin() { return Iterator(m_glava); }
    Iterator<T> end() { return Iterator<T>(nullptr); }
};

int main()
{
    Lista<int> l;
    l.dodaj_kraj(10);
    l.dodaj_pocetak(20);
    l.dodaj_pocetak(30);
    l.dodaj_kraj(40);
    l.dodaj_kraj_v2(50);

    l.ispisi_primitivno();
    std::cout << " <- Prije brisanja 10.\n";

    l.obrisi(10);

    for (auto &el : l)
        std::cout
            << el << " ";
    std::cout << " <- Poslije brisanja 10.\n";

    l.obrisi2(40);
    for (auto &el : l)
        std::cout
            << el << " ";
    std::cout << " <- Poslije brisanja 40 sa obrisi2.";
    return 0;
}
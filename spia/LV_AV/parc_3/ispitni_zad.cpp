/* Implementirati listu i implementirati metodu merge sort */
/* Ispitni zadatak za maksimalne bodove */

#include <iostream>

template <typename T>
class Lista
{
    class Cvor
    {
    public:
        T vrijednost;
        Cvor *sljedeci;

        Cvor() : sljedeci(nullptr) {}
        Cvor(T vrijednost) : vrijednost(vrijednost), sljedeci(nullptr) {}
        // Destruktor viška ~Cvor() { delete sljedeci; }
    };

    Cvor *glava;

public:
    Lista() : glava(nullptr) {}
    // Falio Copy konstruktor
    Lista(const Lista<T> &druga) : glava(nullptr)
    {
        *this = druga;
    }
    ~Lista() { ocisti(); }

    void ocisti()
    {
        auto tekuci = glava;
        while (tekuci != nullptr)
        {
            auto za_obrisat = tekuci;
            tekuci = tekuci->sljedeci;
            delete za_obrisat;
        }
        glava = nullptr;
    }

    void operator=(const Lista<T> &druga)
    {
        ocisti();
        auto tekuci = druga.glava;
        while (tekuci != nullptr)
        {
            dodaj(tekuci->vrijednost);
            tekuci = tekuci->sljedeci;
        }
    }

    void dodaj(T v)
    {
        if (glava == nullptr)
        {
            glava = new Cvor(v);
        }
        else
        {
            auto tekuci = glava;
            while (tekuci->sljedeci != nullptr)
            {
                tekuci = tekuci->sljedeci;
            }
            auto za_dodati = new Cvor(v);
            tekuci->sljedeci = za_dodati;
        }
    }

    int duzina()
    {
        int brojac = 0;
        auto tekuci = glava;
        while (tekuci != nullptr)
        {
            brojac++;
            tekuci = tekuci->sljedeci;
        }
        return brojac;
    }

    void merge_sort()
    {
        if (duzina() == 0)
            throw std::invalid_argument("Lista je prazna");
        else if (duzina() == 1)
            return;
        else if (duzina() == 2)
        {
            if (glava->vrijednost > glava->sljedeci->vrijednost)
                std::swap(glava->vrijednost, glava->sljedeci->vrijednost);
            return;
        }

        Lista<T> l_l, l_d;

        int brojac = 0;
        auto tekuci = glava;
        while (tekuci != nullptr)
        {
            if (brojac % 2 == 0)
            {
                l_l.dodaj(tekuci->vrijednost);
            }
            else
            {
                l_d.dodaj(tekuci->vrijednost);
            }
            brojac++;
            tekuci = tekuci->sljedeci;
        }

        l_l.merge_sort();
        l_d.merge_sort();

        Lista<T> privremena;
        auto p1 = l_l.glava;
        auto p2 = l_d.glava;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->vrijednost < p2->vrijednost)
            {
                privremena.dodaj(p1->vrijednost);
                p1 = p1->sljedeci;
            }
            else
            {
                privremena.dodaj(p2->vrijednost);
                p2 = p2->sljedeci;
            }
        }

        while (p1 != nullptr)
        {
            privremena.dodaj(p1->vrijednost);
            p1 = p1->sljedeci;
        }
        while (p2 != nullptr)
        {
            privremena.dodaj(p2->vrijednost);
            p2 = p2->sljedeci;
        }

        *this = privremena;
    }

    void ispisi()
    {
        auto tekuci = glava;
        while (tekuci != nullptr)
        {
            T vr = tekuci->vrijednost;
            std::cout << vr << " ";
            tekuci = tekuci->sljedeci;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Lista<int> l;
    l.dodaj(6);
    l.dodaj(5);
    l.dodaj(4);
    l.dodaj(3);
    l.dodaj(2);
    l.dodaj(1);
    l.ispisi();
    l.merge_sort();
    l.ispisi();
    return 0;
}
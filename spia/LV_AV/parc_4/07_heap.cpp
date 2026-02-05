#include <iostream>
#include <string>
#include <compare>

class Zahtjev {
private:
    std::string imeKlijenta;
    int prioritet;
public:
    Zahtjev() {}

    Zahtjev(std::string aImeKlijenta, int aPrioritet): 
        imeKlijenta(aImeKlijenta),
        prioritet(aPrioritet) {}

    friend std::ostream& operator<<(std::ostream& os, const Zahtjev& z) {
        os << z.imeKlijenta << "(" << z.prioritet << ")";
        return os;
    }

    std::strong_ordering operator<=>(Zahtjev const &z) const {
        if (prioritet < z.prioritet)
            return std::strong_ordering::less;

        if (prioritet == z.prioritet)
            return std::strong_ordering::equal;

        return std::strong_ordering::greater;
    }

    void PovecajPrioritet(int delta) {
        prioritet += delta;
    }
};

template<typename T>
class Heap {
private:
    T* niz;
    size_t alociranaVelicina;
    size_t velicina;

    inline int roditelj(int dijete) { return (dijete-1)/2; }
    inline int dijete(int roditelj) { return 2*roditelj+1; } // daće prvo ("lijevo") dijete, drugo dijete će biti 2*roditelj+2

    void propagirajNavise(int p) { // propagiramo navise niz[p]
        while (p > 0) {
            auto r = roditelj(p);

            if (niz[r] < niz[p])
                break;

            std::swap(niz[p], niz[r]);
            p = r;
        }
    }

    void propagirajNanize(int p) {
        while (true) {
            auto d = dijete(p);
            if (d >= velicina) // u nizu su zauzete pozicije od 0 .. velicina - 1
                break;

            if (d + 1 < velicina && niz[d+1] < niz[d])
                d++; // spuštam se niz manje dijete
            
            if (niz[p] < niz[d])
                break;

            std::swap(niz[p], niz[d]);
            p = d;
        }
    }

public:
    Heap() {
        alociranaVelicina = 7;
        niz = new T[alociranaVelicina];
        velicina = 0;
    }

    ~Heap() {
        delete[] niz;
    }

    void DodajBezOcuvanjaSvojstvaHeapa(const T& element) {
        if (velicina == alociranaVelicina) {
            std::cout << "Desava se resize!\n";
            // trebamo rasti
            auto novaAlociranaVelicina = 2*alociranaVelicina+1;
            auto noviNiz = new T[novaAlociranaVelicina];
            for (int i = 0; i < velicina; i++) 
                noviNiz[i] = niz[i];
            delete[] niz;
            niz = noviNiz;
            alociranaVelicina = novaAlociranaVelicina;
        }
        niz[velicina++] = element;
    }

    void Dodaj(const T& element) {
        DodajBezOcuvanjaSvojstvaHeapa(element);
        propagirajNavise(velicina-1); // percolate up
    }

    T ObrisiMin() {
        if (velicina == 0) 
            throw std::runtime_error("Heap je prazan!");

        auto M = niz[0];
        niz[0] = niz[--velicina];

        propagirajNanize(0);

        return M;
    }

    friend std::ostream& operator<<(std::ostream& os, Heap<T>& h) {
        int brojElemenataUNivou = 1;
        int elementUNivou = 0;
        for (int i = 0; i < h.velicina; i++) {
            os << h.niz[i];
            elementUNivou++;
            if (elementUNivou == brojElemenataUNivou) {
                os << std::endl;
                elementUNivou = 0;
                brojElemenataUNivou *= 2;
            } else {
                os << " ";
            }
        }

        return os;
    }

    void NapraviHeap() { // Heapify
        for (int i = (velicina-1)/2; i >= 0; i--) { // želimo da izbjegnemo da radimo za one čvorove koji nemaju djece
            propagirajNanize(i);
        }
    }

    // promjena prioriteta
    // ako povećavamo vrijednost, onda idemo na propagiranje naniže
    // ako smanjujemo vrijednost, onda idemo na propagiranje naviše
    void PovecajPrioritet(int pozicija, int delta) {
        niz[pozicija].PovecajPrioritet(delta);
        if (delta > 0) 
            propagirajNanize(pozicija);
        else if (delta < 0)
            propagirajNavise(pozicija);
    }

    // pretraga

};


int main() {
    /*
    Heap<Zahtjev> h;
    h.Dodaj(Zahtjev("Aleksandar", 10));
    h.Dodaj(Zahtjev("A", 20));
    h.Dodaj(Zahtjev("B", 5));
    h.Dodaj(Zahtjev("C", 8));
    h.Dodaj(Zahtjev("D", 16));
    h.Dodaj(Zahtjev("E", 33));
    h.Dodaj(Zahtjev("F", 2));
    h.Dodaj(Zahtjev("G", 15));
    h.Dodaj(Zahtjev("H", 1));

    std::cout << "------------\n";
    std::cout << h << std::endl;

    auto m = h.ObrisiMin();
    std::cout << "------------\n";
    std::cout << "Min = " << m << "\n";

    std::cout << "------------\n";
    std::cout << h << std::endl;

    auto m1 = h.ObrisiMin();
    std::cout << "------------\n";
    std::cout << "Min1 = " << m1 << "\n";

    std::cout << "------------\n";
    std::cout << h << std::endl;

    // Zahtjev z("Aleksandar", 10);
    // Zahtjev z1("Zijad", 8);
    // if (z1 < z) { std::cout << "Jeste manje!"; }
    // 
    // std::cout << z;
    */

    Heap<Zahtjev> h;
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("Aleksandar", 10));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("A", 20));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("B", 5));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("C", 8));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("D", 16));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("E", 33));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("F", 2));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("G", 15));
    h.DodajBezOcuvanjaSvojstvaHeapa(Zahtjev("H", 1));

    h.NapraviHeap();
    std::cout << h << std::endl;

    h.PovecajPrioritet(3, 10);
    std::cout << h << std::endl;

    return 0;
}
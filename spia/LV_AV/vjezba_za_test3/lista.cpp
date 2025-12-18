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
        Cvor(T vrijednost) : vrijednost(vrijednost) {}
        ~Cvor()
        {
            // TODO
        }
    };
    Cvor *glava;
};
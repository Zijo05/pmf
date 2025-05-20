#include <iostream>

int main()
{
    // Unos prirodnog broja n
    std::cout << "Unesite n: ";
    unsigned int n;
    std::cin >> n;

    // Izračun verižnog razlomka
    double suma(0);
    while (n != 0)
    {
        suma = 1 / (n + suma);
        n--;
    }

    // Ispis vrijednosti razlomka
    std::cout << "Vrijednost razlomka: " << suma;

    return 0;
}
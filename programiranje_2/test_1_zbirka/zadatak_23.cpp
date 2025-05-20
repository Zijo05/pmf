#include <iostream>

int main()
{
    // Unos broja
    std::cout << "Unesite n: ";
    unsigned int n;
    std::cin >> n;

    // Izračun sume
    double suma(0), suma_elemenata(0);
    for (int i(0); i < n; i++)
    {
        std::cout << "Unesite " << i + 1 << ". broj: ";
        double broj;
        std::cin >> broj;
        suma_elemenata += broj;
        suma += 1 / suma_elemenata;
    }

    // Ispis sume
    std::cout << "Suma je: " << suma;

    return 0;
}
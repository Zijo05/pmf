#include <iostream>
#include <cmath>

bool je_prost(unsigned int n)
{
    if (n == 1 || n == 0)
        return false;
    for (unsigned int i(2); i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    // Unos n
    std::cout << "Unesite n: ";
    unsigned int n;
    std::cin >> n;

    // Pronalazak n-tog prostog broja
    unsigned int n_ti_prost_broj;
    for (unsigned int i(2), redni_broj(0); redni_broj < n; i++)
        if (je_prost(n_ti_prost_broj = i))
            redni_broj++;

    // Ispis n-tog prostog broja
    std::cout << n << ". prost broj: " << n_ti_prost_broj;

    return 0;
}
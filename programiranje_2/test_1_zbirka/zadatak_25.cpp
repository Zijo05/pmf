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
    // Unos granica m i n
    std::cout << "Unesite granice m i n: ";
    unsigned int m, n;
    std::cin >> m >> n;

    // Pronalazak manjeg od dva broja
    if (n < m)
    {
        unsigned int temp(m);
        m = n;
        n = temp;
    }

    // Ispis prostih brojeva
    std::cout << "Prosti brojevi u intervalu prirodnih brojeva [" << m << ", " << n << "] su: ";
    for (int i(m); i <= n; i++)
        if (je_prost(i))
            std::cout << i << " ";

    return 0;
}
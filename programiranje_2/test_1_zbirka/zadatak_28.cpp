#include <iostream>
#include <iomanip>

unsigned int suma_djelioca(unsigned int n)
{
    unsigned int suma(n);
    for (unsigned int i(1); i <= n / 2; i++)
        if (n % i == 0)
            suma += i;
    return suma;
}

int main()
{
    // Unos granica m1 i m2
    std::cout << "Unesi granice m1 i m2: ";
    unsigned int m1, m2;
    std::cin >> m1 >> m2;

    // Pronalazak manjeg od dva broja
    if (m2 < m1)
    {
        unsigned int temp(m1);
        m1 = m2;
        m2 = temp;
    }

    // Ispis i izračun suma djelioca prirodnih brojeva [m1, m2]
    std::cout << " _________ _________________ \n";
    std::cout << "|         |                 |\n";
    std::cout << "|    n    | suma djelioca n |\n";
    std::cout << "|_________|_________________|\n";
    for (unsigned int i(m1); i <= m2; i++)
    {
        std::cout << "|         |                 |\n";
        std::cout << "|" << std::setw(7) << i << "  |" << std::setw(16) << suma_djelioca(i) << " |\n";
        std::cout << "|_________|_________________|\n";
    }

    return 0;
}
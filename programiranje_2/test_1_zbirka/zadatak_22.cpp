#include <iostream>

int main()
{
    double x;
    std::cout << "Unesi x: ";
    std::cin >> x;

    unsigned int N;
    std::cout << "Unesi N: ";
    std::cin >> N;

    double suma(0);
    for (unsigned int i(N); i != -1; i--)
    {
        double koeficijent;
        std::cout << "Unesite koeficijent uz x^" << i << " : ";
        std::cin >> koeficijent;
        suma = suma * x + koeficijent;
    }

    std::cout << "P(x) = " << suma;

    return 0;
}
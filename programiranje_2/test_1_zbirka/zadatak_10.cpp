#include <iostream>

int main()
{
    double x;
    unsigned int n;

    std::cout << "Unesite x: ";
    std::cin >> x;
    std::cout << "Unesite n: ";
    std::cin >> n;

    short znak(-1);
    double suma(0);
    for (unsigned int k(1); k <= n; k++, znak *= -1)
        suma += znak / (x * (x + k));

    std::cout << "Suma: " << suma;
    return 0;
}
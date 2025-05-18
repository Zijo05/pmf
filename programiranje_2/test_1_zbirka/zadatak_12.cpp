#include <iostream>
#include <cmath>

int main()
{
    double n, suma(0), proizvod(1);
    unsigned int brojac(0);
    while (std::cin >> n, n != 0)
    {
        suma += n;
        proizvod *= n;
        brojac++;
    }

    std::cout << "\nAritmeticka sredina:  " << suma / brojac;
    std::cout << "\nGeometrijska sredina: " << pow(proizvod, 1.0 / brojac);

    return 0;
}
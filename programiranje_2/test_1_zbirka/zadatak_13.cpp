#include <iostream>
#include <cmath>
int main()
{
    int a, b;
    std::cout << "Unesite vrijednosti za interval (a, b): ";
    std::cin >> a >> b;

    for (int i(a); i < b; i++)
    {
        int suma_djelioca(0);
        for (int j(1); j <= i / 2; j++)
            if (i % j == 0)
                suma_djelioca += j;
        if (suma_djelioca == i)
            std::cout << i << " ";
    }
}
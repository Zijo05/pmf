#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
double F(const std::vector<double> &v)
{
    double suma(0);
    for (int i(v.size() - 1); i >= 0; i--)
    {
        if (suma + v[i] < 0)
            throw std::domain_error("Potkorijena velicina je negativna");
        suma = sqrt(suma + v[i]);
    }

    return suma;
}

int main()
{
    unsigned int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    std::vector<double> v(n);
    std::cout << "Unesite " << n << " brojeva: ";
    for (unsigned int i(0); i < n; i++)
    {
        std::cin >> v[i];
    }
    try
    {
        std::cout << std::fixed << std::setprecision(5) << F(v);
    }
    catch (std::domain_error e)
    {
        std::cout << e.what();
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>

double F(std::vector<double> &v)
{
    double suma(0);
    double sumaelemenata(0);
    for (int i(0); i < v.size(); i++)
    {
        sumaelemenata += v[i];
        suma += 1 / sumaelemenata;
    }
    return suma;
}
int main()
{
    std::vector<double> v = {5, 8, 99, 100, -10, -50};
    std::cout << std::fixed << std::setprecision(5) << F(v);
}
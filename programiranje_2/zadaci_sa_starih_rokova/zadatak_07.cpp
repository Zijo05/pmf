#include <iostream>
#include <vector>
#include <functional>

template <typename T>
std::function<T(T)> f(std::vector<T> &v)
{
    return [v](T x)
    {
        T stepen_x(1);
        T suma(0);
        for (int i(0); i < v.size(); i++)
        {
            suma += v[i] * stepen_x;
            stepen_x *= x;
        }

        return suma;
    };
}

int main()
{
    int n;
    std::cout << "Unesite n: ";
    std::cin >> n;
    std::vector<double> v(n);

    for (int i(0); i < n; i++)
    {
        std::cin >> v[i];
    }

    double x;
    std::cout << "Unesite x: ";
    std::cin >> x;

    auto F = f(v);

    std::cout << F(x);
    return 0;
}
#include <iostream>
#include <cmath>

void ocisti()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int main()
{
    double a, b, c;
    std::cout << "Unesite koeficient uz x^2: ";
    std::cin >> a;
    ocisti();
    std::cout << "Unesite koeficient uz x: ";
    std::cin >> b;
    ocisti();
    std::cout << "Unesite slobodni koeficent: ";
    std::cin >> c;
    ocisti();
    if (a == 0)
    {
        if (b == 0 && c != 0)
            std::cout << "Jednacina nema rjesenja!";
        else if (b == 0 && c == 0)
            std::cout << "Jednacina ima besk.mnogo rjesenja!";
        else
            std::cout << "x= " << -c / b;
    }
    else
    {
        double D(b * b - 4 * a * c);
        if (D == 0)
            std::cout << "x1 = x2 = " << -b / 2 * a;
        else if (D > 0)
        {
            std::cout << "x1 = " << (-b + sqrt(D)) / 2 * a << std::endl;
            std::cout << "x2 = " << (-b - sqrt(D)) / 2 * a << std::endl;
        }
        else
        {
            if (a > 0)
            {
                std::cout << "x1=" << -b / 2 * a << " + " << sqrt(-D) / 2 * a << "i" << std::endl;
                std::cout << "x2=" << -b / 2 * a << " - " << sqrt(-D) / 2 * a << "i" << std::endl;
            }
            else
            {
                std::cout << "x1=" << -b / 2 * a << " - " << sqrt(-D) / 2 * a << "i" << std::endl;
                std::cout << "x2=" << -b / 2 * a << " + " << sqrt(-D) / 2 * a << "i" << std::endl;
            }
        }
    }
    return 0;
}
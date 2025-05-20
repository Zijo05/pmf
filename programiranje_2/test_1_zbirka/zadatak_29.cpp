#include <iostream>

double f(double a, int n = 1)
{
    double stepen = a;
    bool negativan = false;
    if (n <= 0)
    {
        if (n == 0)
            return 1;
        negativan = true;
        n = -n;
    }
    while (n != 1)
    {
        stepen *= a;
        n--;
    }
    if (negativan)
        return 1 / stepen;
    return stepen;
}

int main()
{
    std::cout << "2^6 = " << f(2, 6);
    std::cout << "\n2^0 = " << f(2, 0);
    std::cout << "\n10^-3 = " << f(10, -3);
    std::cout << "\n5^2 = " << f(5, 2);
    std::cout << "\n5^1 = " << f(5);
    std::cout << "\n5^1 = " << f(5, 1);

    return 0;
}
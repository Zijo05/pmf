#include <iostream>
#include <cmath>

bool je_prost(unsigned int n)
{
    if (n == 1 || n == 0)
        return false;
    for (unsigned int i(2); i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void f(int &n, int &n1, int &n2, int &n3, int &n4)
{
    n1 = 0;
    n2 = 1;
    n3 = 0;
    n4 = 1;
    n = n < 0 ? -n : n;
    while (n != 0)
    {
        if (je_prost(n % 10))
            n2 *= n % 10;
        else
            n4 *= n % 10;
        if ((n % 10) % 2 == 0)
            n1 += n % 10;
        else
            n3 += n % 10;
        n /= 10;
    }
}

int main()
{
    int n;
    std::cout << "Unesite n: ";
    std::cin >> n;

    int n1, n2, n3, n4;

    f(n, n1, n2, n3, n4);
    std::cout << "n1: " << n1 << " | n2: " << n2 << " | n3: " << n3 << " | n4: " << n4;

    return 0;
}
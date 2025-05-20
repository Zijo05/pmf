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
void obrni_cifre(int &n)
{
    int obrnuto = 0;
    n = n < 0 ? -n : n;
    while (n != 0)
    {
        obrnuto = obrnuto * 10 + n % 10;
        n /= 10;
    }
    n = obrnuto;
}
void f(int n, unsigned int &m, unsigned int &k)
{
    obrni_cifre(n);
    m = 0;
    k = 0;
    while (n != 0)
    {
        if (je_prost(n % 10))
            m = m * 10 + n % 10;
        else
            k = k * 10 + n % 10;
        n /= 10;
    }
}

int main()
{
    int n;
    std::cout << "Unesite n: ";
    std::cin >> n;
    unsigned int m, k;
    f(n, m, k);
    std::cout << "m: " << m << "\nk: " << k;

    return 0;
}
#include <iostream>

void obrni(int &n)
{
    n = n < 0 ? -n : n;
    int obrnuti = 0;
    while (n != 0)
    {
        obrnuti = obrnuti * 10 + n % 10;
        n /= 10;
    }
    n = obrnuti;
}

void f(int &n, int &m, int &k)
{
    m = 0;
    k = 0;
    obrni(n);
    while (n != 0)
    {
        if ((n % 10) % 2 == 0)
            m = m * 10 + n % 10;
        else
            k = k * 10 + n % 10;
        n /= 10;
    }
}

int main()
{
    int m, k, n;
    std::cout << "Unesite n: ";
    std::cin >> n;
    f(n, m, k);

    std::cout << "m = " << m << "\nk = " << k;

    return 0;
}
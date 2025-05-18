#include <iostream>

int main()
{
    int a, b, c, d, e, f;
    std::cout << "Unesite 6 cijelih brojeva: ";
    std::cin >> a >> b >> c >> d >> e >> f;

    unsigned int broj_pozitivnih(0);
    unsigned int broj_neparnih(0);

    if (a > 0)
    {
        broj_pozitivnih++;
        if (a % 2 != 0)
            broj_neparnih++;
    }
    if (b > 0)
    {
        broj_pozitivnih++;
        if (b % 2 != 0)
            broj_neparnih++;
    }
    if (c > 0)
    {
        broj_pozitivnih++;
        if (c % 2 != 0)
            broj_neparnih++;
    }
    if (d > 0)
    {
        broj_pozitivnih++;
        if (d % 2 != 0)
            broj_neparnih++;
    }
    if (e > 0)
    {
        broj_pozitivnih++;
        if (e % 2 != 0)
            broj_neparnih++;
    }
    if (f > 0)
    {
        broj_pozitivnih++;
        if (f % 2 != 0)
            broj_neparnih++;
    }

    if (broj_pozitivnih == 0)
        std::cout << "Nema pozitivnih brojeva!";
    else
        std::cout << "Unijeli ste " << broj_pozitivnih << " pozitivnih brojeva, a medju njima je " << broj_neparnih << " neparnih brojeva.";

    return 0;
}
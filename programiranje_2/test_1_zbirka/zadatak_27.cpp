#include <iostream>

bool djeljiv_sa_sumom_svojih_cifara(unsigned int n)
{
    unsigned int suma(0);
    unsigned int privremena = n;
    while (privremena != 0)
    {
        suma += privremena % 10;
        privremena /= 10;
    }
    return n % suma == 0;
}

int main()
{
    // Unos granica a i b
    std::cout << "Unesite granice a i b: ";
    unsigned int a, b;
    std::cin >> a >> b;

    // Pronalazak manjeg od dva broja
    if (b < a)
    {
        unsigned int temp(a);
        a = b;
        b = temp;
    }

    // Izracun broja brojeva djeljivih sa sumom svojih cifara
    unsigned int broj(0);
    for (unsigned int i(a); i <= b; i++)
        if (djeljiv_sa_sumom_svojih_cifara(i))
            broj++;
    // Ispis broja navedenih brojeva
    std::cout << "Na intervalu [" << a << ", " << b << "] postoji " << broj << " prirodnih brojeva koji su djeljivi sa sumom svojih cifara";
    return 0;
}
#include <iostream>

double cvorovi_u_kmh(unsigned int cvorovi)
{
    return (cvorovi * 1852) / 1000.0;
}

int main()
{
    unsigned int brzina_u_cvorovima;
    std::cout << "Unesite brzinu u cvorovima: ";
    std::cin >> brzina_u_cvorovima;
    std::cout << "Brzina u km/h: " << cvorovi_u_kmh(brzina_u_cvorovima);

    return 0;
}
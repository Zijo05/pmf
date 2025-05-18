#include <iostream>

bool jesu_li_stranice_pravouglog(double a, double b, double c)
{
    double hipotenuza(std::max(a, std::max(b, c)));

    return (a * a + b * b + c * c - hipotenuza * hipotenuza) == (hipotenuza * hipotenuza);
}

int main()
{
    double a, b, c;
    std::cout << "Unesite stranice: ";
    std::cin >> a >> b >> c;

    if (jesu_li_stranice_pravouglog(a, b, c))
        std::cout << "Unesene stranice cine pravougli trougao.";
    else
        std::cout << "Unesene stranice ne cine pravougli trougao.";

    return 0;
}
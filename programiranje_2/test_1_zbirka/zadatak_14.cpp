#include <iostream>

int main()
{
    unsigned int n;
    std::cout << "Unesi n: ";
    std::cin >> n;

    unsigned int kopija = n;
    unsigned int obrat(0);
    while (kopija != 0)
    {
        obrat = obrat * 10 + kopija % 10;
        kopija /= 10;
    }

    if (n == obrat)
        std::cout << "Broj je palindroman.";
    else
        std::cout << "Broj nije palindroman.";

    return 0;
}
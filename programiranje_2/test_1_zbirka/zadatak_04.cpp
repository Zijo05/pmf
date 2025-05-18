#include <iostream>

int main()
{
    unsigned int sati_koristenja;
    std::cout << "Unesite sate koristenja: ";
    std::cin >> sati_koristenja;

    double firma1(10 + .50 * sati_koristenja);
    double firma2(.80 * sati_koristenja);

    if (firma1 < firma2)
        std::cout << "Isplativija je prva firma.";
    else
        std::cout << "Isplativija je druga firma.";

    return 0;
}
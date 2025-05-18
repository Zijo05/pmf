#include <iostream>
int main()
{
    double x;
    std::cout << "Unesite broj: ";
    std::cin >> x;
    if (!std::cin)
        std::cout << "Uneseni podatak nije broj!";
    else if (x - int(x) == 0)
    {
        if (x > 0)
            std::cout << "Uneseni broj je prirodan.";
        else
            std::cout << "Uneseni broj je cijeli, ali nije prirodan.";
    }
    else
        std::cout << "Uneseni broj je realan, ali nije cijeli.";

    return 0;
}
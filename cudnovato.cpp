#include <iostream>
#include <vector>
#include <string>

template <typename T>

std::vector<T> f(T *niz1, int duzina1, T *niz2, int duzina2)
{
    std::vector<T> rezultat = {};

    for (int i = 0; i < duzina2; i++)
    {
        for (int j = 0; j < *(niz2 + i); j++)
        {
            int broj(niz1[i]);
            std::cout << broj << " ";
            rezultat.push_back(broj);
        }
    }
    std::cout << std::endl;
    for (int r = 0; r < rezultat.size(); r++)
    {
        std::cout << rezultat[r] << " ";
    }

    return rezultat;
}

int main()
{
    int niz1[] = {2, 4, 9, 10};
    int niz2[] = {1, 3, 3, 4};

    int duzina1 = sizeof(niz1) / sizeof(niz1[0]);
    int duzina2 = sizeof(niz2) / sizeof(niz2[0]);

    f(niz1, duzina1, niz2, duzina2);
}
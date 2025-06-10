#include <iostream>
template <typename T>

T f(T **M, int kolone, int vrste, T i, T j)
{
    int brojac = 0;
    for (int q = 0; q < vrste; q++)
    {
        for (int w = 0; w < kolone; w++)
        {
        }
    }

    int suma = 0;
    int x = i;
    int y = j;
    // dole desno
    while (x + 1 < vrste && y + 1 < kolone)
    {
        x++;
        y++;
        suma = suma + M[x][y];
    };
    x = i;
    y = j;
    // dole lijevo
    while (x + 1 < vrste && y - 1 >= 0)
    {
        x++;
        y--;
        suma = suma + M[x][y];
    }
    x = i;
    y = j;
    // gore lijevo
    while (x - 1 >= 0 && y - 1 >= 0)
    {
        x--;
        y--;
        suma = suma + M[x][y];
    }
    x = i;
    y = j;
    // gore desno
    while (x - 1 >= 0 && y + 1 < kolone)
    {
        x--;
        y++;
        suma = suma + M[x][y];
    }
    return suma;
}

int main()
{
    int vrste;
    int kolone;
    int i, j;

    std::cout << "unesite broj redova: ";
    std::cin >> vrste;

    std::cout << "unesite broj kolona: ";
    std::cin >> kolone;

    std::cout << "kordinate elementa (i,j): ";
    std::cin >> i >> j;

    int **M = nullptr;
    try
    {
        int **M = new int *[vrste];
        for (int i = 0; i < vrste; i++)
        {
            M[i] = new int[kolone];
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << &e;
        return 1;
    }
    i--;
    j--;
    if (i < 0 or j < 0)
    {
        std::cout << "ne mogu kordinate biti manje od 0!";
    }
    else if (i > vrste or j > kolone)
    {
        std::cout << "ne mogu kordinate biti vece od broja kolona ili vrsti! ";
    }
    else
    {
        for (int c = 0; c < vrste; c++)
        {
            for (int r = 0; r < kolone; r++)
            {
                std::cin >> M[c][r];
            }
        }
        std::cout << f(M, kolone, vrste, i, j);
    }
}
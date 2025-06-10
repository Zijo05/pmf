#include <iostream>

template <typename T>
bool ponavlja_se(T **&M, unsigned int k, unsigned int v, T broj)
{
    unsigned int brojac(0);
    for (unsigned int i(0); i < v; i++)
        for (unsigned int j(0); j < k; j++)
            if (M[i][j] == broj)
                brojac++;

    return brojac > 1;
}

template <typename T>
T f(T **&M, unsigned int k, unsigned int v, unsigned int i, unsigned int j)
{
    for (unsigned int i(0); i < v; i++)
        for (unsigned j(0); j < k; j++)
            if (ponavlja_se(M, k, v, M[i][j]))
                throw std::string("U matrici postoje dva ili vise jednakih elemenata!");

    if (i < 1 || j < 1 || i > v || j > k)
        throw std::range_error("Unesene koordinate (i, j) ne postoje u unesenoj matrici!");

    T suma(0);
    int razlika = (i - 1) - (j - 1);
    int zbir = (i - 1) + (j - 1);
    for (unsigned int x(0); x < v; x++)
        for (unsigned int y(0); y < k; y++)
            if (x - y == razlika || x + y == zbir)
                suma += M[x][y];

    return suma - M[i - 1][j - 1];
}

int main()
{
    std::cout << "Unesite broj vrsta: ";
    unsigned int v;
    std::cin >> v;

    std::cout << "Unesite broj kolona: ";
    unsigned int k;
    std::cin >> k;

    double **matrica = nullptr;

    try
    {
        matrica = new double *[v];
        for (int i(0); i < v; i++)
            matrica[i] = new double[k];
    }
    catch (const std::bad_alloc &e)
    {
        system("cls");
        std::cout << "Nedovoljno memorije za alokaciju!";
        for (int i(0); i < v; i++)
            delete[] matrica[i];
        delete[] matrica;
        return 0;
    }
    std::cout << "Unesite matricu: \n";
    for (int i(0); i < v; i++)
        for (int j(0); j < k; j++)
            std::cin >> matrica[i][j];

    std::cout << "Unesite koordinate (i, j) elementa matrice: ";
    unsigned int i, j;
    std::cin >> i >> j;
    try
    {
        double suma = f(matrica, k, v, i, j);
        std::cout << "Trazena suma: " << suma;
    }
    catch (const std::string &e)
    {
        std::cout << e;
    }
    catch (const std::range_error &e)
    {
        std::cout << e.what();
    }

    return 0;
}
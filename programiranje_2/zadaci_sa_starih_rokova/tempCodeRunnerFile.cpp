#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

template <typename T>
bool ponavlja_se(T **&M, unsigned int vrste, T &broj)
{
    unsigned int brojac(0);
    for (unsigned int i(0); i < vrste; i++)
        if (M[i][0] == broj)
            brojac++;
    return brojac > 1;
}

template <typename T>
void nadji_referentnu_tacku(T **&M, unsigned int vrste)
{
    unsigned int indeks_najveci_x(0);
    int indeks_najmanji_y(-1);
    for (unsigned int i(1); i < vrste; i++)
        if (M[i][0] > M[indeks_najveci_x][0])
            indeks_najveci_x = i;

    if (ponavlja_se(M, vrste, M[indeks_najveci_x][0]))
    {
        for (unsigned int i(0); i < vrste; i++)
            if ((indeks_najmanji_y == -1 || M[i][1] < M[indeks_najmanji_y][1]) && M[indeks_najveci_x][0] == M[i][0])
                indeks_najmanji_y = i;
    }

    T temp_x = M[0][0];
    T temp_y = M[0][1];

    if (indeks_najmanji_y == -1)
    {
        M[0][0] = M[indeks_najveci_x][0];
        M[0][1] = M[indeks_najveci_x][1];

        M[indeks_najveci_x][0] = temp_x;
        M[indeks_najveci_x][1] = temp_y;
    }
    else
    {
        M[0][0] = M[indeks_najmanji_y][0];
        M[0][1] = M[indeks_najmanji_y][1];

        M[indeks_najmanji_y][0] = temp_x;
        M[indeks_najmanji_y][1] = temp_y;
    }
}

template <typename T>
double izracunaj_ugao(T **&M, unsigned int indeks)
{
    double ugao(atan2(M[indeks][1] - M[0][1], M[indeks][0] - M[0][0]));
    if (ugao < 0)
        ugao += 2 * M_PI;
    return ugao;
}

template <typename T>
void zamijeni_tacke(T **&M, unsigned int a, unsigned int b)
{
    T temp_x = M[a][0];
    T temp_y = M[a][1];

    M[a][0] = M[b][0];
    M[a][1] = M[b][1];

    M[b][0] = temp_x;
    M[b][1] = temp_y;
}

template <typename T>
void kreirajProstPoligon(T **&A, unsigned int m)
{
    for (int i = 0; i < m - 2; i++)
        for (int j = 1; j < m - i - 1; j++)
            if (izracunaj_ugao(A, j) < izracunaj_ugao(A, j + 1))
                zamijeni_tacke(A, j, j + 1);
}

int main()
{
    std::cout << "Unesite broj tacaka m: ";
    unsigned int m;
    std::cin >> m;

    double **matrica = new double *[m];
    for (int i(0); i < m; i++)
        matrica[i] = new double[2];

    std::cout << "Unesite matricu: \n";
    for (int i(0); i < m; i++)
        for (int j(0); j < 2; j++)
            std::cin >> matrica[i][j];

    nadji_referentnu_tacku(matrica, m);
    kreirajProstPoligon(matrica, m);
    std::cout << "Poligon: \n";
    for (int i(0); i < m; i++)
    {
        for (int j(0); j < 2; j++)
            std::cout << std::fixed << std::setprecision(1) << matrica[i][j] << " ";
        std::cout << std::endl;
    }
}
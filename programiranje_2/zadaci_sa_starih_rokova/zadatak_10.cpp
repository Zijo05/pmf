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
    return atan((M[indeks][1] - M[0][1]) / (M[indeks][0] - M[0][0]));
}

template <typename T>
void kreirajProstPoligon(T **&A, unsigned int m)
{
    auto cmp = [A](T *a, T *b)
    {
        double dx1 = a[0] - A[0][0];
        double dy1 = a[1] - A[0][1];
        double dx2 = b[0] - A[0][0];
        double dy2 = b[1] - A[0][1];
        double cross = dx1 * dy2 - dy1 * dx2;
        if (fabs(cross) < 1e-9)
        {
            // Ako su kolinearne, bliža tačka ide prva
            double d1 = dx1 * dx1 + dy1 * dy1;
            double d2 = dx2 * dx2 + dy2 * dy2;
            return d1 < d2;
        }
        return cross > 0;
    };
    std::sort(A + 1, A + m, cmp);
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

    for (int i = 0; i < m; i++)
        delete[] matrica[i];
    delete[] matrica;
}

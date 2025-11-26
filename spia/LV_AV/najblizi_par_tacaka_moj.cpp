#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tacka
{
    double x;
    double y;
};

double udaljenost(const Tacka &t1, const Tacka &t2)
{
    return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

bool sortiraj_po_x(const Tacka &t1, const Tacka &t2) { return t1.x < t2.x; }
bool sortiraj_po_y(const Tacka &t1, const Tacka &t2) { return t1.y < t2.y; }

double najblizi_par_rek(vector<Tacka> &v, int p, int k, Tacka &t1, Tacka &t2)
{
    // BAZNI SLUCAJ
    if (p == k - 1)
    {
        t1 = v[p];
        t2 = v[p + 1];
        return udaljenost(t1, t2);
    }
    else if (p + 2 == k)
    {
        auto d1 = udaljenost(v[p], v[p + 1]);
        auto d2 = udaljenost(v[p], v[p + 2]);
        auto d3 = udaljenost(v[p + 1], v[p + 2]);

        if (d1 < d2 && d1 < d3)
        {
            t1 = v[p];
            t2 = v[p + 1];
            return d1;
        }
        else if (d2 < d3)
        {
            t1 = v[p];
            t2 = v[p + 2];
            return d2;
        }
        else
        {
            t1 = v[p + 1];
            t2 = v[p + 2];
            return d3;
        }
    }

    // REKURZIJA (POLOVLJENJE)
    Tacka l1, l2;
    Tacka r1, r2;
    auto sredina = (p + k) / 2;

    double lijevi_dio = najblizi_par_rek(v, p, sredina, l1, l2);
    double desni_dio = najblizi_par_rek(v, sredina + 1, k, r1, r2);

    double delta = min(lijevi_dio, desni_dio);
    if (lijevi_dio < desni_dio)
    {
        t1 = l1;
        t2 = l2;
    }
    else
    {
        t1 = r1;
        t2 = r2;
    }

    // SPAJANJE (GRANIČNI SLUČAJ)
    Tacka pivot = v[sredina];
    vector<Tacka> traka;

    for (int i(p); i <= k; i++)
        if (abs(v[i].x - pivot.x) < delta)
            traka.push_back(v[i]);

    sort(traka.begin(), traka.end(), sortiraj_po_y);
    for (int i(0); i < traka.size() - 1; i++)
    {
        for (int j(i + 1); j < traka.size() && abs(traka[i].y - traka[j].y) < delta; j++)
        {
            double d = udaljenost(traka[i], traka[j]);
            if (d < delta)
            {
                delta = d;
                t1 = traka[i];
                t2 = traka[j];
            }
        }
    }

    return delta;
}

double najblizi_par(vector<Tacka> &v, Tacka &t1, Tacka &t2)
{
    if (v.empty())
        throw invalid_argument("Vektor je prazan!");
    else if (v.size() == 1)
        throw invalid_argument("Vektor ima samo jednu tacku!");

    sort(v.begin(), v.end(), sortiraj_po_x);
    return najblizi_par_rek(v, 0, v.size() - 1, t1, t2);
}

int main()
{

    return 0;
}
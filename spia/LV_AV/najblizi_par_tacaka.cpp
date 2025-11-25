#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Tacka
{
    double m_x, m_y;

public:
    Tacka(double x = 0, double y = 0)
    {
        m_x = x;
        m_y = y;
    }

    double getX() const { return m_x; }
    double getY() const { return m_y; }
};

double udaljenost(const Tacka &x, const Tacka &y)
{
    return sqrt(pow(x.getX() - y.getX(), 2) + pow(x.getY() - y.getY(), 2));
}

double najblizi_par_rek(vector<Tacka> &v, int odindeksa, int doindeksa, Tacka &prva, Tacka &druga)
{
    // BAZNI SLUCAJEVI (Tvoj originalni kod, ispravan je)
    if (odindeksa == doindeksa)
        throw invalid_argument("Ovo se ne bi smjelo desiti");
    else if (odindeksa + 1 == doindeksa)
    {
        prva = v[odindeksa];
        druga = v[doindeksa];
        return udaljenost(prva, druga);
    }
    else if (odindeksa + 2 == doindeksa)
    {
        auto d1 = udaljenost(v[odindeksa], v[odindeksa + 1]);
        auto d2 = udaljenost(v[odindeksa], v[odindeksa + 2]);
        auto d3 = udaljenost(v[odindeksa + 1], v[odindeksa + 2]);

        if (d1 < d2 && d1 < d3)
        {
            prva = v[odindeksa];
            druga = v[odindeksa + 1];
            return d1;
        }
        else if (d2 < d3)
        {
            prva = v[odindeksa];
            druga = v[odindeksa + 2];
            return d2;
        }
        else
        {
            prva = v[odindeksa + 1];
            druga = v[odindeksa + 2];
            return d3;
        }
    }

    // REKURZIVNI KORAK
    auto sredina = (odindeksa + doindeksa) / 2;
    Tacka l1, l2;
    Tacka r1, r2;

    auto dlijeva = najblizi_par_rek(v, odindeksa, sredina, l1, l2);
    auto ddesna = najblizi_par_rek(v, sredina + 1, doindeksa, r1, r2);

    auto daljina = min(dlijeva, ddesna);

    // Azuriranje referenci na trenutno najbolji par
    if (dlijeva < ddesna)
    {
        prva = l1;
        druga = l2;
    }
    else
    {
        prva = r1;
        druga = r2;
    }

    // COMBINE KORAK (POJAS)
    auto srednjaTacka = v[sredina];
    vector<Tacka> pojas;

    for (int i = odindeksa; i <= doindeksa; i++)
    {
        if (abs(v[i].getX() - srednjaTacka.getX()) < daljina)
            pojas.push_back(v[i]);
    }

    sort(pojas.begin(), pojas.end(), [](const Tacka &a, const Tacka &b)
         { return a.getY() < b.getY(); });

    for (int i = 0; i < pojas.size(); i++)
    {
        // Unutrasnja petlja se prekida cim je razlika po Y veca od 'daljina'
        // Ovo garantuje da se petlja vrti max 7 puta (konstantna slozenost)
        for (int j = i + 1; j < pojas.size() && (pojas[j].getY() - pojas[i].getY()) < daljina; j++)
        {
            auto d = udaljenost(pojas[i], pojas[j]);
            if (d < daljina)
            {
                daljina = d;
                prva = pojas[i];
                druga = pojas[j];
            }
        }
    }

    return daljina;
}

double najblizi_par(vector<Tacka> &v, Tacka &prva, Tacka &druga)
{
    if (v.size() <= 1)
        throw std::invalid_argument("Ova funkcija zahtijeva barem dvije tacke");

    sort(v.begin(), v.end(), [](Tacka &a, Tacka &b)
         { return a.getX() < b.getX(); });

    return najblizi_par_rek(v, 0, v.size() - 1, prva, druga);
}

int main()
{
    vector<Tacka> v{
        Tacka(1, 0),
        Tacka(2, 2),
        Tacka(2, 3),
        Tacka(4, 6),
        Tacka(8, 9),
        Tacka(8.5, 9)};

    Tacka a, b;

    try
    {
        double min_dist = najblizi_par(v, a, b);
        cout << "Najmanja udaljenost: " << min_dist << endl;
        cout << "Izmedju tacaka: (" << a.getX() << ", " << a.getY() << ") i ("
             << b.getX() << ", " << b.getY() << ")" << endl;
    }
    catch (const exception &e)
    {
        cout << "Greska: " << e.what() << endl;
    }

    return 0;
}
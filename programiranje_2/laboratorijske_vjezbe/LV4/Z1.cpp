#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// https://en.cppreference.com/w/cpp/error/exception
double f(double niz[], int n)
{
    double rez = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        rez += niz[i];

        if (rez < 0)
        {
            throw domain_error("Izuzetak: Potkorjena velicina je negativna.");
            // throw "Potkorjena velicina je negativna!";
            // throw n;
        }
        rez = sqrt(rez);
    }
    return rez;
}

int main()
{

    double a[100];
    int n;
    cout << "Unesite n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Unesite " << i + 1 << ". broj: ";
        cin >> a[i];
    }

    try
    {
        cout << f(a, n);
    }
    catch (domain_error greska)
    {
        cout << greska.what() << endl;
    }
    catch (const char poruka[])
    {
        cout << poruka << endl;
    }
    catch (int broj)
    {
        cout << broj << endl;
    }

    catch (...)
    {
        cout << "Greska!" << endl;
    }

    cout << "Program se nastavlja od ove naredbe...." << endl;

    return 0;
}

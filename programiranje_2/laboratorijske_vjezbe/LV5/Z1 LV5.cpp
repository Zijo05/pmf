

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename Tip>
void ispisi(Tip pocetak, Tip iza_kraja)
{
    for (Tip pok = pocetak; pok != iza_kraja; pok++)
        cout << *pok << " ";
}

template <typename Tip>
void ispisiNiz(Tip *niz, int n)
{
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";
}

template <typename Tip>
void Obrni(Tip *pocetak, Tip *iza_kraja)
{
    Tip *lijevi(pocetak);
    Tip *desni(iza_kraja - 1);

    while (lijevi < desni)
    {
        Tip temp = *lijevi;
        *lijevi = *desni;
        *desni = temp;
        lijevi++;
        desni--;
    }
}

template <typename Tip>
void Obrni2(Tip pocetak, Tip iza_kraja)
{
    Tip lijevi(pocetak);
    Tip desni(iza_kraja - 1);

    while (lijevi < desni)
    {
        swap(*lijevi, *desni);
        lijevi++;
        desni--;
    }
}

int main()
{

    int niz[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Obrni(niz, niz + 10);
    ispisiNiz(niz, 10);
    cout << endl;

    vector<string> v{"a", "b", "c", "d", "e", "f"};
    //   Obrni(v.begin(), v.end());
    Obrni(&v[0], &v[6]);
    ispisi(&v[0], &v[6]);
    cout << endl;
    Obrni2(v.begin(), v.end());
    for (auto el : v)
        cout << el << " ";

    return 0;
}

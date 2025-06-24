#include <iostream>
using namespace std;

struct Datum
{
private:
    int dan;
    int mjesec;
    int godina;

public:
    Datum()
    {
        dan = 1;
        mjesec = 1;
        godina = 2000;
    }
    Datum(int d, int m, int g)
    {
        dan = d;
        mjesec = m;
        godina = g;
    }
    void ispisi()
    {
        cout << dan << ". " << mjesec << ". " << godina << ". ";
    }
};

class Radnik
{
protected:
    string ime;
    string prezime;
    Datum datum_rodjenja;

public:
    Radnik(string i, string p, Datum d) : ime(i), prezime(p), datum_rodjenja(d) {}
    virtual double getPlata() = 0;
    virtual void ispisiPodatke() = 0; // virtuelna klasa -  necemo moci kreirati objekte tipa Radnik
                                      // implementacija ove funkcije ce postojati u izvedenim klasama

    string getIme() { return ime; }
    void setIme(string i) { ime = i; }

    string getPrezime() { return prezime; }
    void setPrezime(string p) { prezime = p; }

    Datum getDatum() const { return datum_rodjenja; }
    void setDatum(Datum d) { datum_rodjenja = d; }
};

class Direktor : public Radnik
{
    const double plata;

public:
    Direktor(string i, string p, double pl, Datum d) : Radnik(i, p, d), plata(pl) {}
    // U konstruktorskoj inicijalizatorskoj listi treba pozvati konstruktor klase Radnik

    double getPlata() override { return plata; }

    void ispisiPodatke() override
    {
        cout << "Direktor " << ime << " " << prezime << " ima platu " << getPlata() << endl;
    }
};

class SefOdjela : public Radnik
{
    double satnica;
    double brojRadnihSati;
    Direktor *nadredjeni;

public:
    SefOdjela(string i, string p, Datum dat, double s, double bs, Direktor *d) : Radnik(i, p, dat)
    {
        satnica = s;
        brojRadnihSati = bs;
        nadredjeni = d;
    }
    double getPlata() override { return satnica * brojRadnihSati; }

    void ispisiPodatke() override
    {
        cout << "Sef odjela " << ime << " " << prezime << " ima platu " << getPlata() << endl;
        cout << "Nadredjeni je " << nadredjeni->getIme() << " " << nadredjeni->getPrezime() << endl;
    }

    void postaviNadredjenog(Direktor *d) { nadredjeni = d; }
};

class Zaposlenik : public Radnik
{
    double satnica;
    double brojRadnihSati;
    SefOdjela *nadredjeni;

public:
    Zaposlenik(string i, string p, Datum d, double s, double bs, SefOdjela *sef) : Radnik(i, p, d)
    {
        satnica = s;
        brojRadnihSati = bs;
        nadredjeni = sef;
    }

    double getPlata() override { return satnica * brojRadnihSati; }
    void ispisiPodatke() override
    {
        cout << "Zaposlenik " << ime << " " << prezime << " ima platu " << getPlata() << endl;
        cout << "Nadredjeni je " << nadredjeni->getIme() << " " << nadredjeni->getPrezime() << endl;
    }
    void postaviNadredjenog(SefOdjela *d) { nadredjeni = d; }
};

int main()
{
    // Radnik r("xx", "yy");
    // Radnik niz[3];

    Direktor d1("D", "D", 3000, Datum(1, 1, 2000));
    SefOdjela s1("X", "Y", Datum(1, 1, 2000), 8, 300, &d1);

    Radnik *niz[3];
    niz[0] = &d1;
    niz[1] = &s1;
    niz[2] = new Zaposlenik("A", "B", Datum(1, 1, 2000), 8, 200, &s1);

    for (int i(0); i < 3; i++)
    {
        niz[i]->ispisiPodatke();
        cout << endl;
    }

    return 0;
}

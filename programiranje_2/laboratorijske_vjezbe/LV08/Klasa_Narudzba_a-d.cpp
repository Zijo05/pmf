#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Datum
{
    int dan;
    int mjesec;
    int godina;

public:
    Datum()
    {
        dan = 0;
        mjesec = 0;
        godina = 0;
    }
    Datum(int d, int m, int g)
    {
        dan = d;
        mjesec = m;
        godina = g;
    }
    void setDan(int d) { dan = d; }
    void setMjesec(int m) { mjesec = m; }
    void setGodina(int g) { godina = g; }
    int getDan() { return dan; }
    int getMjesec() { return mjesec; }
    int getGodina() { return godina; }
    void ispisi()
    {
        cout << dan << "." << mjesec << "." << godina << ".";
    }
    bool podesenDatum()
    {
        return dan != 0 && mjesec != 0 && godina != 0;
    }
};

class Kupac
{
    string naziv;
    string adresa;
    string mjesto;
    string drzava;

public:
    Kupac(string n, string a, string m, string d)
    {
        naziv = n;
        adresa = a;
        mjesto = m;
        drzava = d;
    }
    string getNaziv() { return naziv; }
    string getAdresa() { return adresa; }
    string getMjesto() { return mjesto; }
    string getDrzava() { return drzava; }
};

class StavkaNarudzbe
{
    string naziv_artikla;
    double kolicina;
    double cijena;

public:
    StavkaNarudzbe(string naziv, double kol, double c)
    {
        naziv_artikla = naziv;
        kolicina = kol;
        cijena = c;
    }

    double cijena_stavke()
    {
        return kolicina * cijena;
    }

    void ispisi()
    {
        cout << "Naziv: " << naziv_artikla << " KOL: " << kolicina << " Cijena: " << cijena << endl
             << cijena_stavke() << endl;
    }
};

class Narudzba
{

    Datum datum_narudzbe;
    string komercijalista;
    Kupac kupac;

public:
    vector<StavkaNarudzbe> stavke_narudzbe;
    string getKomercijalista() { return komercijalista; }
    Datum getDatum() { return datum_narudzbe; }
    Kupac getKupac() { return kupac; }
    Narudzba(string komercijalista, Kupac kupac) : kupac(kupac)
    {
        this->komercijalista = komercijalista;
        time_t now = time(0);
        tm *localtm = localtime(&now);
        datum_narudzbe = Datum(localtm->tm_mday, localtm->tm_mon + 1, localtm->tm_year + 1900);
        // https://en.cppreference.com/w/cpp/chrono/c/tm
    }

    bool validnaNarudzba()
    {
        return datum_narudzbe.podesenDatum() &&
               komercijalista != "" &&
               kupac.getNaziv() != "" &&
               stavke_narudzbe.size() > 0;
    }

    double iznosNarudzbe()
    {
        double iznos = 0;
        for (auto stavka : stavke_narudzbe)
        {
            iznos += stavka.cijena_stavke();
        }
        return iznos;
    }

    void ispisiNarudzbu()
    {
        for (auto stavka : stavke_narudzbe)
            stavka.ispisi();
        cout << "Datum: ";
        datum_narudzbe.ispisi();
        cout << endl;
        cout << "Komercijalista: " << komercijalista << endl
             << "Kupac: " << kupac.getNaziv() << endl
             << "Ukupno:" << iznosNarudzbe();
    }

    void dodajStavku(StavkaNarudzbe stavka)
    {
        stavke_narudzbe.push_back(stavka);
    }
};

int main()
{

    Narudzba n("komercijalista1", Kupac("k1", "Zmaja od Bosne", "Sarajevo", "BIH"));
    n.dodajStavku(StavkaNarudzbe("Sok", 10, 2));
    n.dodajStavku(StavkaNarudzbe("Voda", 100, 1));

    n.ispisiNarudzbu();
}

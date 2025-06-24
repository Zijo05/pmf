#include <iostream>

struct Datum
{
private:
    unsigned short dan;
    unsigned short mjesec;
    unsigned short godina;

public:
    Datum(unsigned short dan, unsigned short mjesec, unsigned short godina) : dan(dan), mjesec(mjesec), godina(godina) {}
    void ispisiDatum()
    {
        std::cout << dan << "." << mjesec << "." << godina << ".";
    }
};

class Radnik
{
protected:
    std::string ime;
    std::string prezime;
    Datum datum_rodjenja;

public:
    Radnik(std::string ime, std::string prezime, Datum datum_rodjenja) : ime(ime), prezime(prezime), datum_rodjenja(datum_rodjenja) {}
    virtual double getPlata() = 0;
    virtual void ispisiPodatke() = 0;
    std::string getIme() { return ime; }
    std::string getPrezime() { return prezime; }
};

class Direktor : public Radnik
{
private:
    double const plata;

public:
    Direktor(std::string ime, std::string prezime, Datum datum_rodjenja, double plata) : Radnik(ime, prezime, datum_rodjenja), plata(plata) {}
    double getPlata() override
    {
        return plata;
    }
    void ispisiPodatke() override
    {
        std::cout << "Ime i prezime: " << ime << " " << prezime;
        std::cout << "\nDatum rodjenja: ";
        datum_rodjenja.ispisiDatum();
        std::cout << "\nPlata: " << getPlata();
    }
};

class SefOdjela : public Radnik
{
private:
    double satnica;
    double broj_radnih_sati;
    Direktor *nadredjeni;

public:
    SefOdjela(std::string ime, std::string prezime, Datum datum_rodjenja, double satnica, double broj_radnih_sati, Direktor *nadredjeni) : Radnik(ime, prezime, datum_rodjenja), satnica(satnica), broj_radnih_sati(broj_radnih_sati), nadredjeni(nadredjeni) {}
    double getPlata() override
    {
        return broj_radnih_sati * satnica;
    }

    void ispisiPodatke() override
    {
        std::cout << "Ime i prezime: " << ime << " " << prezime;
        std::cout << "\nDatum rodjenja: ";
        datum_rodjenja.ispisiDatum();
        std::cout << "\nNadredjeni: " << nadredjeni->getIme() << " " << nadredjeni->getPrezime();
        std::cout << "\nPlata: " << getPlata();
    }
};

class Zaposlenik : public Radnik
{
private:
    double satnica;
    double broj_radnih_sati;
    SefOdjela *nadredjeni;

public:
    Zaposlenik(std::string ime, std::string prezime, Datum datum_rodjenja, double satnica, double broj_radnih_sati, SefOdjela *nadredjeni) : Radnik(ime, prezime, datum_rodjenja), satnica(satnica), broj_radnih_sati(broj_radnih_sati), nadredjeni(nadredjeni) {}
    double getPlata() override
    {
        return broj_radnih_sati * satnica;
    }

    void ispisiPodatke() override
    {
        std::cout << "Ime i prezime: " << ime << " " << prezime;
        std::cout << "\nDatum rodjenja: ";
        datum_rodjenja.ispisiDatum();
        std::cout << "\nNadredjeni: " << nadredjeni->getIme() << " " << nadredjeni->getPrezime();
        std::cout << "\nPlata: " << getPlata();
    }
};

int main()
{
    Radnik *radnici[3];
    /*
    radnici[0] = new Direktor("Direktor", "Direktorovic", Datum(15, 7, 2005), 2000);
    radnici[1] = new SefOdjela("Sefo", "Sefovic", Datum(15, 5, 1999), 20, 150, static_cast<Direktor *>(radnici[0]));
    radnici[2] = new Zaposlenik("Rado", "Radic", Datum(23, 3, 2001), 15, 150, static_cast<SefOdjela *>(radnici[1]));
    */

    /* Drugi nacin*/
    Direktor direktor("Direktor", "Direktorovic", Datum(15, 7, 2005), 2000);
    SefOdjela sefodjela("Sefo", "Sefovic", Datum(15, 5, 1999), 20, 150, &direktor);
    Zaposlenik zaposlenik("Rado", "Radic", Datum(23, 3, 2001), 15, 150, &sefodjela);
    radnici[0] = &direktor;
    radnici[1] = &sefodjela;
    radnici[2] = &zaposlenik;

    for (int i(0); i < 3; i++)
    {
        radnici[i]->ispisiPodatke();
        std::cout << "\n\n";
    }
    for (int i(0); i < 3; i++)
        delete radnici[i];

    return 0;
}
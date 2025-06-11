#include <iostream>
#include <vector>
#include <ctime>

class StavkaNarudzbe{
    std::string naziv_artikla;
    unsigned int kolicina;
    double cijena;

};

class Komercijalista{};

class Kupac{};

class Datum{
    unsigned short dan;
    unsigned short mjesec;
    unsigned short godina;

    public:
    Datum(unsigned short dan, unsigned short mjesec, unsigned short godina)
        : dan(dan), mjesec(mjesec), godina(godina) {}
    Datum(short x)
        : dan(getDanasnjiDan()), mjesec(getDanasnjiMjesec()), godina(getDanasnjaGodina()) {}
    Datum()
        : dan(0), mjesec(0), godina(0) {}

    Datum vrati_naredni_datum(){
        tm datum = {};
        datum.tm_mday = this->dan;
        datum.tm_mon = this->mjesec - 1;
        datum.tm_year = this->godina - 1900;

        time_t vrijeme = mktime(&datum);
        vrijeme += 60 * 60 * 24;

        tm *noviDatum = localtime(&vrijeme);
        return Datum(noviDatum->tm_mday, noviDatum->tm_mon + 1, noviDatum->tm_year + 1900);
    }

    private:
        unsigned short getDanasnjiDan(){
            time_t sada = time(0);
            tm *localtm = localtime(&sada);
            return localtm->tm_mday;
        }
        unsigned short getDanasnjiMjesec(){
            time_t sada = time(0);
            tm *localtm = localtime(&sada);
            return localtm->tm_mon + 1;
        }
        unsigned short getDanasnjaGodina(){
            time_t sada = time(0);
            tm *localtm = localtime(&sada);
            return localtm->tm_year + 1900;
        }
};

class Narudzba{
    Datum datum;
    Komercijalista komercijalista;
    Kupac kupac;
    
    public:
    std::vector<StavkaNarudzbe> stavke_narudzbe;
    
    Narudzba()

};
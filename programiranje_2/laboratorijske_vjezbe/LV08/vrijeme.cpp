#include <iostream>
#include <ctime>

int main()
{
    time_t sada = time(0);
    tm *lokalno_vrijeme_sada = localtime(&sada);

    tm datum = {};
    datum.tm_mday = 15;          // 15. // this->dan
    datum.tm_mon = 12 - 1;       // Decembar // this->mjesec - 1
    datum.tm_year = 2025 - 1900; // 2025. godina // this->godina - 1900

    time_t vrijeme = mktime(&datum);
    vrijeme += 60 * 60 * 24; // Pomjeramo se sa 60*60*24 sekundi tj. jedan dan

    tm *noviDatum = localtime(&vrijeme);
    unsigned short noviDan = noviDatum->tm_mday;
    unsigned short noviMjesec = noviDatum->tm_mon + 1;
    unsigned short novaGodina = noviDatum->tm_year + 1900;

    return 0;
}
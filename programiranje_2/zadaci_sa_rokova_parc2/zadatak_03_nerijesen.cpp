#include <iostream>

class Segment{
    std::pair<double, double> pocetakS;
    std::pair<double, double> krajS;
    unsigned int kapacitet;
    unsigned int brojDodatihS;
    

    bool jelDegenerisan() const{
        return (pocetakS.first == krajS.first && pocetakS.second == krajS.second);
    }
public:
    Segment(std::pair<double, double> pocetak, std::pair<double, double> kraj, unsigned int kapacitet)
        : pocetakS(pocetak), krajS(kraj), kapacitet(kapacitet), brojDodatihS(0) {}
    ~Segment() = default;

    unsigned int vratiBrojPresjekaS() const;


};

int main() {
    
    
    return 0;
}
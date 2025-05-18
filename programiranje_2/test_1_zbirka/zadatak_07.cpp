#include <iostream>
#include <iomanip>
int main()
{
    unsigned int glavnica;
    int kamatna_stopa;
    std::cout << "Unesite glavnicu: ";
    std::cin >> glavnica;
    std::cout << "Unesite kamatnu stopu: ";
    std::cin >> kamatna_stopa;

    int kamata(glavnica * (kamatna_stopa / 100.0));
    unsigned int nova_svota(glavnica + kamata);

    std::cout << "\nGlavnica:      " << std::setw(6) << glavnica;
    std::cout << "\nKamatna stopa: " << std::setw(6) << kamatna_stopa;
    std::cout << "\nKamata:        " << std::setw(6) << kamata;
    std::cout << "\nNova svota:    " << std::setw(6) << nova_svota;
    return 0;
}
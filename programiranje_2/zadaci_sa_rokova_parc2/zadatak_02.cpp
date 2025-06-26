#include <iostream>
#include <vector>

struct Mapa{
    std::vector<std::pair<char, char>> parovi;

    Mapa(std::initializer_list<std::pair<char, char>> init) : parovi(init) {}

    char operator[](const char &c) const {
        for (const auto &par : parovi) 
            if (par.first == c) 
                return par.second; // Vraća zamjenski karakter ako postoji

        return c; // Ako nema zamjene, vrati originalni karakter
    }
};

std::string monoalfabetskiSistem(std::string s, const Mapa &mapa){
    for (auto &karakter : s) {
        karakter = mapa[karakter];
    }
    return s;
}

int main() {
    Mapa kljuc{
        std::make_pair('a', 'b'), std::make_pair('b', 'c'), std::make_pair('c', 'd'), std::make_pair('d', 'e'), std::make_pair('e', 'f'), 
        std::make_pair('f', 'g'), std::make_pair('g', 'h'), std::make_pair('h', 'i'), std::make_pair('i', 'j'), std::make_pair('j', 'k'), 
        std::make_pair('k', 'l'), std::make_pair('l', 'm'), std::make_pair('m', 'n'), std::make_pair('n', 'o'), std::make_pair('o', 'p'),
        std::make_pair('p', 'q'), std::make_pair('q', 'r'), std::make_pair('r', 's'), std::make_pair('s', 't'), std::make_pair('t', 'u'), 
        std::make_pair('u', 'v'), std::make_pair('v', 'w'), std::make_pair('w', 'x'), std::make_pair('x', 'y'), std::make_pair('y', 'z')
    };

    std::string tekst = "abcxyz";
    std::string sifriraniTekst = monoalfabetskiSistem(tekst, kljuc);

    std::cout << "Originalni tekst: " << tekst << std::endl;
    std::cout << "Sifrirani tekst: " << sifriraniTekst << std::endl; // Treba ispisati "bcdyzz"

    return 0;
}
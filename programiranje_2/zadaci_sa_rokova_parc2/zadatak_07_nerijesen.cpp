#include<iostream>
#include<vector>

using par = std::pair<int, int>;

class Domina {
    int a, b;
public:
    Domina(int a, int b) : a(a), b(b) {}
    Domina() : a(0), b(0) {}

    int geta() const {return a;}
    int getb() const {return b;}

    Domina& operator~() {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    friend bool operator==(const Domina& d1, const Domina& d2) {
        if((d1.a == d2.a && d1.b == d2.b) || (d1.a == d2.b && d1.b == d2.a))
            return true;
        return false;
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Domina& d) {
        ispis << "(" << d.a << "," << d.b << ")";
        return ispis;
    }
};

class Skup {
    void kopiraj(const Skup& s) {domine = s.domine;}
    void obrisi() {domine.clear();}
protected:
    std::vector<Domina> domine;
public:    
    Skup() = default;
    Skup(const Skup& s) {kopiraj(s);}
    virtual ~Skup() {obrisi();};

    Skup& operator=(const Skup& s) {
        if(this != &s) {obrisi(); kopiraj(s);}
        return *this;
    }

    virtual bool operator+=(const Domina& d) = 0; 

    bool jelSadrzi(const Domina& d) {
        for(const auto& domina : domine)
            if(domina == d)
                return true;
        return false;
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Skup& s) {
        for(const auto& domina : s.domine)
            ispis << domina;
        return ispis;
    }
};

class Kutija : public Skup {
public:
    bool operator+=(const Domina& d) override {
        if(jelSadrzi(d)) return false;
        domine.push_back(d);
        return true;
    }; 

    Kutija& ubaci(std::vector<par>& vd) {
        for(const auto& pr : vd)
            *this += Domina(pr.first, pr.second);
        return *this;
    }

    bool isprazni(Domina& domina) {
        
    }
};

int main() {
    
    
    return 0;
}
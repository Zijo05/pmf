#include <iostream>
#include <cstring>
#include <algorithm>

class Vektor3D {
    double x, y, z;
public:
    explicit Vektor3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Vektor3D() : x(0), y(0), z(0) {}

    friend bool operator==(const Vektor3D& v1, const Vektor3D& v2) {
        return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
    }

    friend bool operator<(const Vektor3D& v1, const Vektor3D& v2) {
        double intenzitet1 = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
        double intenzitet2 = v2.x * v2.x + v2.y * v2.y + v2.z * v2.z;
        return intenzitet1 < intenzitet2;
    }

    friend bool operator>(const Vektor3D& v1, const Vektor3D& v2) {
        double intenzitet1 = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
        double intenzitet2 = v2.x * v2.x + v2.y * v2.y + v2.z * v2.z;
        return intenzitet1 > intenzitet2;
    }

    friend Vektor3D operator+(const Vektor3D& v1, const Vektor3D& v2) {
        return Vektor3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    friend Vektor3D& operator+=(Vektor3D& v1, const Vektor3D& v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        v1.z += v2.z;
        return v1;
    }

    friend Vektor3D operator*(const Vektor3D& v1, const double& sk) {
        return Vektor3D(v1.x * sk, v1.y * sk, v1.z * sk);
    }

    friend Vektor3D operator*(const double& sk, const Vektor3D& v1) {
        return Vektor3D(v1.x * sk, v1.y * sk, v1.z * sk);
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Vektor3D& v) {
        ispis << "(" << v.x << "," << v.y << "," << v.z << ")";
        return ispis;
    }

    friend std::istream& operator>>(std::istream& unos, Vektor3D& v) {
        unos >> v.x;
        unos >> v.y;
        unos >> v.z;
        return unos;
    }
};

class Jedinka{
    Vektor3D vP;
    Vektor3D vB;
public:
    explicit Jedinka(const Vektor3D& vP, const Vektor3D& vB) : vP(vP), vB(vB) {}

    Jedinka() : vP(Vektor3D()), vB(Vektor3D()) {}

    const Vektor3D& getVP() const {
        return vP;
    }

    const Vektor3D& getVB() const {
        return vB;
    }

    friend Jedinka& operator<<=(Jedinka& j, double t) {
        j.vP += j.vB * t;
        return j;
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Jedinka& j) {
        ispis << "[" << j.vP << "|" << j.vB << "]";
        return ispis;
    }
    
};

class Greska1 : public std::runtime_error {
public:
    explicit Greska1(const char* poruka) : std::runtime_error(poruka) {}
};

class Greska2 : public std::runtime_error {
public:
    explicit Greska2(const char* poruka) : std::runtime_error(poruka) {}
};

class Jato {
public:
    char* ime;
    Jedinka* niz;
    unsigned int maxKapacitet;
    unsigned int brojDodatihJ = 0;
    void baciG2() const {
        throw Greska2("Neispravan indeks!");
    }
public:
    explicit Jato(const char* ime, unsigned int maxKapacitet = 50)
        : ime(ime ? new char[strlen(ime) + 1] : nullptr),
          niz(new Jedinka[maxKapacitet]),
          maxKapacitet(maxKapacitet),
          brojDodatihJ(0)
    {
        if (ime) {
            strcpy(this->ime, ime);
        }
    }
    ~Jato() {
        delete[] ime;
        delete[] niz;
    }

    Jato(const Jato& j) : ime(j.ime ? new char[strlen(j.ime) + 1] : nullptr), niz(new Jedinka[maxKapacitet]), maxKapacitet(j.maxKapacitet), brojDodatihJ(j.brojDodatihJ) {
        strcpy(ime, j.ime);

        for (unsigned int i = 0; i < brojDodatihJ; i++) {
            niz[i] = j.niz[i];
        }
    }

    Jato& operator=(const Jato& j) {
        if (this != &j) {
            delete[] ime;
            delete[] niz;
            maxKapacitet = j.maxKapacitet;
            brojDodatihJ = j.brojDodatihJ;

            ime = j.ime ? new char[strlen(j.ime) + 1] : nullptr;
            if (ime)
                strcpy(ime, j.ime);

            niz = new Jedinka[maxKapacitet];
            for (unsigned int i = 0; i < brojDodatihJ; i++)
                niz[i] = j.niz[i];
        }
        return *this;
    }

    Jato& operator+=(const Jedinka& j) {
        if (brojDodatihJ < maxKapacitet) {
            if(true || brojDodatihJ == 0 || !(niz[brojDodatihJ - 1].getVP() > j.getVP())) {
                niz[brojDodatihJ++] = j;
            }

        } else throw Greska1("Nema mjesta u jatu za novu jedinku!");
        return *this;
    }

    const unsigned int& getBrojDodatihJ() const {
        return brojDodatihJ;
    }

    friend Jato& operator <<=(Jato& j, double t) {
        for (unsigned int i = 0; i < j.brojDodatihJ; i++)
            j.niz[i] <<= t;

        std::sort(j.niz, j.niz + j.brojDodatihJ, [](const Jedinka& a, const Jedinka& b) {
            return a.getVB() > b.getVB();
        });
        return j;
    }

    const Jedinka& operator[](unsigned int indeks) const {
        if (indeks < brojDodatihJ) {
            return niz[indeks];
        }
        baciG2();
    }

    friend std::ostream& operator<<(std::ostream& ispis, const Jato& j) {
        ispis << j.ime;
        for (int i(0); i < j.brojDodatihJ; i++) {
            ispis << j.niz[i];
        }
        return ispis;
    }
};

int main() {
    char ime[100];
    std::cin >> ime; 
    Jato jt(ime);

    int n, t; 
    std::cin>> n>>t;

    Vektor3D vP, vB;
    for (int i(0); i < n; i++) {
        std::cin >> vP >> vB;
        jt+= Jedinka(vP, vB);
    }

    std::cout << (jt<<= t);
    return 0;
}
#include <iostream>

class Cvor {
public:
    bool je_li_operacija;
    char operacija;
    int vrijednost;
    Cvor *lijevi, *desni;

    Cvor(bool jlo, char op, int vr) {
        je_li_operacija = jlo;
        operacija = op;
        vrijednost = vr;

        lijevi = nullptr;
        desni = nullptr;
    }
};

class Stablo {

private:
    Cvor* glava;
public:
    Stablo() {
        glava = nullptr;
    }

    void Postavi(Cvor* a_glava) {
        glava = a_glava;
    }

    void unutrasnjaIspisi(Cvor* c) {
        if (c == nullptr) {
            std::cout << "Nesto nismo dobro!\n";
            return;
        }

        if (c->je_li_operacija) {
            std::cout << "(";
            unutrasnjaIspisi(c->lijevi);
            std::cout << ")" << c->operacija << "(";
            unutrasnjaIspisi(c->desni);
            std::cout << ")";
        } else {
            std::cout << c->vrijednost;
        }
    }

    int internoIzracunaj(Cvor* c) {
        if (c->je_li_operacija) {
            auto l = internoIzracunaj(c->lijevi);
            auto d = internoIzracunaj(c->desni);
            switch (c->operacija) {
                case '+':
                    return l+d;
                case '-':
                    return l-d;
                case '*':
                    return l*d;
                case '/':
                    return l/d;
            }
        } else {
            return c->vrijednost;
        }

        return 0; // samo da nema warninga
    }

    int Izracunaj() {
        return internoIzracunaj(glava);
    }

    void Ispisi() {
        unutrasnjaIspisi(glava);
    }

    void unutrasnjaPostfixIspisi(Cvor *c) {
        if (c->je_li_operacija) {
            unutrasnjaPostfixIspisi(c->lijevi);
            unutrasnjaPostfixIspisi(c->desni);
            std::cout << c->operacija << " ";
        } else {
            std::cout << c->vrijednost;
            std::cout << " ";
        }
    }

    void PostfixIspisi() {
        unutrasnjaPostfixIspisi(glava);
    }
};

int main() {
    Cvor* cminus = new Cvor(true, '-', 0);
    Stablo s;
    s.Postavi(cminus);

    Cvor* cplus = new Cvor(true, '+', 0);
    cminus->lijevi = cplus;

    Cvor* c10 = new Cvor(false, 'x', 10);
    cplus->lijevi = c10;

    Cvor* cputa = new Cvor(true, '*', 0);
    cplus->desni = cputa;

    Cvor* c2 = new Cvor(false, 'x', 2);
    cputa->lijevi = c2;

    Cvor* cplus2 = new Cvor(true, '+', 0);
    cputa->desni = cplus2;

    Cvor* c5 = new Cvor(false, 'x', 5);
    cplus2->lijevi = c5;

    Cvor* ckroz = new Cvor(true, '/', 0);
    cplus2->desni = ckroz;

    Cvor* c6 = new Cvor(false, 'x', 6);
    Cvor* c3 = new Cvor(false, 'x', 3);
    ckroz->lijevi = c6;
    ckroz->desni = c3;

    Cvor* c37 = new Cvor(false, 'x', 37);
    cminus->desni = c37;

    s.Ispisi();
    std::cout << "\n";

    s.PostfixIspisi();
    std::cout << "\n";

    std::cout << s.Izracunaj() << "\n";
}


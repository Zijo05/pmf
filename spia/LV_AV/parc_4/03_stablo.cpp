#include <iostream>

using namespace std;

template <typename t>
class Stablo
{
    class Cvor
    {
    public:
        t vrijednost_;
        Cvor *lijevi_;
        Cvor *desni_;
        Cvor(t v) : vrijednost_(v)
        {
            lijevi_ = nullptr;
            desni_ = nullptr;
        }
    };
    Cvor *glava_;

public:
    Stablo() : glava_(nullptr) {}
    ~Stablo()
    {
        // TODO
    }

    void Dodaj(t vrijednost)
    {
        Cvor *c = new Cvor(vrijednost);
        if (glava_ == nullptr)
        {
            glava_ = c;
            return;
        }
        Cvor *tekuci = glava_;
        while (true)
        {
            if (tekuci->vrijednost_ >= vrijednost)
            {
                // moram ići lijevo
                if (tekuci->lijevi_ == nullptr)
                {
                    tekuci->lijevi_ = c;
                    return;
                }
                tekuci = tekuci->lijevi_;
            }
            else
            {
                // moram ići desno
                if (tekuci->desni_ == nullptr)
                {
                    tekuci->desni_ = c;
                    return;
                }
                tekuci = tekuci->desni_;
            }
        }
    }

    void ispisiInternoInfix(Cvor *c)
    {
        if (c == nullptr)
            return;
        ispisiInternoInfix(c->lijevi_);
        cout << c->vrijednost_ << " ";
        ispisiInternoInfix(c->desni_);
    }

    void IspisiInfix()
    {
        ispisiInternoInfix(glava_);
    }

    int visinaInterno(Cvor *c)
    {
        if (c == nullptr)
            return 0;
        int visinaLijevo = visinaInterno(c->lijevi_);
        int visinaDesno = visinaInterno(c->desni_);
        return 1 + max(visinaLijevo, visinaDesno);
    }

    int Visina()
    {
        return visinaInterno(glava_);
    }

    bool imaLiInterno(Cvor *c, t vrijednost)
    {
        if (c == nullptr)
            return false;
        if (c->vrijednost_ == vrijednost)
            return true;
        return imaLiInterno(c->lijevi_, vrijednost) || imaLiInterno(c->desni_, vrijednost);
    }

    bool ImaLi(t vrijednost)
    {
        return imaLiInterno(glava_, vrijednost);
    }

    t Min()
    {
        if (glava_ == nullptr)
            throw runtime_error("Stablo je prazno.");
        Cvor *tekuci = glava_;
        while (tekuci->lijevi_ != nullptr)
        {
            tekuci = tekuci->lijevi_;
        }
        return tekuci->vrijednost_;
    }

    t Max()
    {
        if (glava_ == nullptr)
            throw runtime_error("Stablo je prazno.");
        Cvor *tekuci = glava_;
        while (tekuci->desni_ != nullptr)
        {
            tekuci = tekuci->desni_;
        }
        return tekuci->vrijednost_;
    }

    void Obrisi(t vrijednost)
    {
        if (glava_ == nullptr)
            return;
        Cvor *tekuci = glava_;
        Cvor **pokazivacNaTekuci = &glava_;
        while (tekuci != nullptr)
        {
            if (tekuci->vrijednost_ == vrijednost)
            {
                break;
            }
            if (tekuci->vrijednost_ >= vrijednost)
            {
                // idi lijevo
                pokazivacNaTekuci = &tekuci->lijevi_;
                if (tekuci->lijevi_ == nullptr)
                    throw runtime_error("Element nije u stablu.");
                tekuci = tekuci->lijevi_;
            }
            else
            {
                // idi desno
                pokazivacNaTekuci = &tekuci->desni_;
                if (tekuci->desni_ == nullptr)
                    throw runtime_error("Element nije u stablu.");
                tekuci = tekuci->desni_;
            }
        }

        if (tekuci == nullptr)
            throw runtime_error("Nisam nasao."); // nije pronađen element

        // dakle, trebamo da brišemo tekući.
    }
};

int main()
{
    Stablo<int> s;
    s.Dodaj(10);
    s.Dodaj(50);
    s.Dodaj(25);
    s.Dodaj(30);
    s.Dodaj(1);
    s.Dodaj(45);
    s.Dodaj(80);

    s.IspisiInfix();
    cout << "\n"
         << s.Visina() << endl;
    cout << "Element " << (s.ImaLi(24) ? "se nalazi" : "se ne nalazi") << " u stablu." << endl;
    cout << "Min element u stablu je: " << s.Min() << endl;
    cout << "Max element u stablu je: " << s.Max() << endl;
    return 0;
}
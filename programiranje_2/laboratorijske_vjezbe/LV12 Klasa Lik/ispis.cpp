#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Osoba{
  string ime;
  string prezime;

  public:
  Osoba() {}
  Osoba(string i, string  p):ime(i), prezime(p)  {}

  friend ostream& operator<<(ostream &ispis,const Osoba &a){
   ispis<<a.ime<<" "<<a.prezime;
   return ispis;
  }


   friend istream& operator>>(istream& unos, Osoba& o) {
        return unos >> o.ime >> o.prezime;
    }


};



int main() {
    Osoba o;
    ifstream citac("osobe.txt");
    while(citac>> o)  {
            cout << o <<endl;

    }
    citac.close();

}

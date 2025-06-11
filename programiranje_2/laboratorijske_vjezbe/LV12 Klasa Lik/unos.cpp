#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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

  friend istream& operator>>(istream &unos, Osoba &a){
   unos>>a.ime>>a.prezime;
    return unos;   
  }


};



int main(){
  ofstream ispis("osobe.txt");
   int n; cin>>n;
   for(int i=0; i<n; i++) {
       Osoba os;
       cin >> os;
       ispis << os << endl;
       
       
   }
  ispis.close();
 
 

}

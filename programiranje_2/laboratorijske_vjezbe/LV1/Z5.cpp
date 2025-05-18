#include <iostream>
using namespace std;

int main() {
  int broj_sa_najvise_neparnih, max_broj_neparnih = 0;
  while(true) {
    int trenutni;
    cin>>trenutni;
    if(trenutni == 0)
        break;
    int broj_neparnih = 0;
    int kopija = trenutni;
    while(kopija != 0) {
        int cifra = kopija%10;
        if(cifra % 2 == 1)
            broj_neparnih++;
        kopija /= 10;
    }
    if(broj_neparnih > max_broj_neparnih) {
        broj_sa_najvise_neparnih = trenutni;
        max_broj_neparnih = broj_neparnih;
    }
  }

  cout<<"Broj sa najvise neparnih cifara je "<<broj_sa_najvise_neparnih;

}

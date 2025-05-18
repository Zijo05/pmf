#include<iostream>
using namespace std;


/*
int brojTrocifrenih(const int *pocetak, int *iza_kraja) {
  int brojac = 0;

  for(int *pok = pocetak; pok < iza_kraja; pok++)
    if(*pok >= 100 && *pok <= 999)
      brojac++;

  return brojac;

}

*/


int broj_trocifrenih(int* p, int* q) {
    int brojac = 0;
    while (p < q) {       
  //cout << p << " "<< q << endl;
   //cout << *p << " " << *q << endl;
        if (*p > 99 and *p < 1000) 
            brojac++;
        
        p++; 
    }
    return brojac;
}

int main() {
    int niz[]{1, 200, 300, 4, 5};
    cout<<broj_trocifrenih(niz, niz+5);
    return 0;
}





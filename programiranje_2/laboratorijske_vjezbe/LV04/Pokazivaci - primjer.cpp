#include<iostream>
#include<cmath>
using namespace std;


void Ispisi(int *niz, int n) {
  int *pok = &niz[0];
  for(int i=0;i<n;i++)
    cout<<*(pok+i)<<" ";
  cout<<endl;
}


void Ispisi2(int *pocetak, int *iza_kraja) {
  for(int *pok = pocetak; pok < iza_kraja; pok++)
    cout<<*pok<<" ";
  cout<<endl;
}
// Za vjezbu:  naci u knjizi prof. Zeljka Jurica  kako se ispisuju elementi niza od posljednjeg ka prvom


int main(){  // TESTIRATI DIO PO DIO
   /*
    int broj(5);
    int *pok = &broj;
    cout<<pok<<" "<<*pok<<endl;
    cout<<2*(*pok) +1<<endl;
*/
    
/*
    int a(3), b(5);
    int *pok1 = &a; // nullptr
    int *pok2 = &b;
    cout<<*pok1<<endl;        // 3
    if (*pok1==*pok2)  cout<<"Isti su"<<endl;
    else cout<<"razliciti ";  //  3!=5, pa ispise razliciti

    pok1 =  pok2 ;       //sada oba pokazivaca pokazuju na b
    cout<<*pok1<<endl;  //5
    if (pok1==pok2)  cout<<"Isti su"<<endl;
    

    // Greske:  int *pok1  = 5; pok = *pok;   *pok= *a;

*/
    int niz[]= {2,3,5,4,11,13};
    int *p = &niz[1];
    cout<<*p<<endl;  //ispise 3
    //p--; //p++
    //cout<<*p<<endl;
    p = p + 4;
    cout<<*p<<endl;

    // cout<<niz[i];  ekvivalentno sa cout<< *(niz+i);

 
    Ispisi(niz,6);
    Ispisi(niz+1,5);
    Ispisi2(niz+1,niz+4);
}

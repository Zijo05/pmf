
#include<iostream>
#include<cmath>
using namespace std;

int main(){
int n(0);
int pomocna(0), obrnutiBroj(0), zadnjaCifra(0);
cout<<"Unesite prirodan broj n ";
cin>>n;
pomocna = n;

while(pomocna!=0) {
     zadnjaCifra = pomocna%10;
     pomocna = pomocna/10;
     obrnutiBroj = obrnutiBroj * 10 +zadnjaCifra;
}
cout<<abs(n-obrnutiBroj);


}

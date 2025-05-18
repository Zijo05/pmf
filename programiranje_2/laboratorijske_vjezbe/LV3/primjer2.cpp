#include<iostream>
using namespace std;
//NIZ KAO PARAMETAR U FUNKCIJI

void promijeni(int niz[], int n){ //clanovi niza se mijenjaju
  for (int i=0; i<n; i++)
        niz[i] ++;
  }

void ispisi(int niz[], int n){
  for (int i=0; i<n; i++)
       cout<<niz[i]<<" ";
  }

int main() {

int a[100];
int n;
cin>>n;
for (int i=0; i<n; i++) cin>>a[i];

promijeni(a,n);
cout<<"Novi niz je: " <<endl;
for (int i=0; i<n; i++) cout<<a[i]<<endl;

ispisi(a,n);
return 0;
}

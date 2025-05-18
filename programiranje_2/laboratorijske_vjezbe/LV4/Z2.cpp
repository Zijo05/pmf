#include<iostream>
using namespace std;

template<typename tip>
void f(tip a[], tip x[], int n ) {
//Npr. a = {2, 3, 4, 5, 6}
//b = {1, 2, 6, 24, 120 }   b[i] je proizvod elemenata lijevo od elementa a[i]
//c= {360, 120, 30, 6, 1 }  c[i] je proizvod elemenata desno od elementa a[i]

int b[100];
b[0]=1;
for(int i=1; i<n; i++) 
    b[i]= b[i-1] * a[i-1];


int c[100];
c[n-1]=1;

for(int i=n-2; i>=0; i--)
    c[i] = c[i+1] * a[i+1];


for(int i=0; i<n; i++) {
        x[i]= b[i]*c[i];
}

}


int main(){
    
    int niz[]{2,3,4,5,6};
    
    int x[]{0,0,0,0,0};
    
    f(niz, x, 5);
    
    for(int i=0; i<5; i++)  cout<<x[i]<<endl;

}



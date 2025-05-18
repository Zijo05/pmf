
#include<iostream>
using namespace std;

long int f(int n)   {

if (n<-1) throw n;

if (n==-1) throw "nije ispravna vrijednost(-1) "; 


long int proizvod(1);
for (int i=1; i<=n; i++)  proizvod*=i; // p = 1*2* ....*n = n!
return proizvod;
}


int main(){

try { cout<<f(-2)<<endl;  
//cout<<f(2)<<endl;
cout<<"Sad smo u try bloku"<<endl;
}
catch(int e) {
 cout<<e<<endl;  // ispise  -2
 cout<<"Sad smo u catch bloku "<<endl;
}

catch(const char poruka[]) {
cout<<poruka;
}

catch(...) {
cout<<"Neki drugi izuzetak";}


cout<<"Nastavljamo"<<endl;

}

//ZADATAK D

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool  f(string s) {
     return s.length()>3;
  }

void podijeli(string* niz, int n, bool (*f)(string&), vector<string*> &v1,  vector<string*> &v2,
              vector<string>&  v3) {
    for(int i=0; i< n; i++)  {
        if (find(v3.begin(), v3.end(), niz[i]) == v3.end())  {
          if (f(niz[i]) ==true) v1.push_back(&niz[i]);
          else v2.push_back(&niz[i]);
         }
    }
}


int main(){
    int n;
    cin>>n;

    string* niz= new string[n];
    string unos;
    cout<<"Unesite rijeci "<<endl;
    cin.ignore(10000, '\n');
    for(int i=0; i<n; i++) {
        getline(cin,unos);
        niz[i]=unos;
    }
    vector<string*> v1;
    vector<string*> v2;
    vector<string>  v3={"a", "b"};

    podijeli(niz,n,  [](string& s){ return s.length()> 3; },  v1, v2, v3);
    for(int i=0; i< v1.size(); i++) cout<<*v1[i]<<" ";
    cout<<endl;
    for(int i=0; i< v2.size(); i++) cout<<*v2[i]<<" ";

    return 0;
}


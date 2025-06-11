//ZADATAK A I B - string* niz

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool  f(string s) {
      if (s.length()>3) {  return true; }
      return false;
  }

void podijeli(string*  niz, int n, bool (*f)(string&), vector<string>&  v1, vector<string> &  v2) {
    for(int i=0; i< n; i++)  {
        if (f(niz[i]) ==true)  v1.push_back(niz[i]);
        else v2.push_back(niz[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}


int main(){

    int n;
    cout<<"Unesite n"<<endl;
    cin>>n;

    string*  niz = new string[n];

    string unos;

    cin.ignore(10000, '\n');
    cout<<"Unesite rijeci"<<endl;
    for(int i=0; i< n; i++) {
        getline(cin, unos);
        niz[i]=unos;
    }

    vector<string> v1;
    vector<string> v2;

    podijeli(niz, n, [](string &s){ return s.length()>3;},  v1,   v2);

    for(int i=0; i< v1.size(); i++) cout<<v1[i]<<" ";
    cout<<endl;
    for(int i=0; i< v2.size(); i++) cout<<v2[i]<<" ";
    cout<<endl;

    return 0;
}

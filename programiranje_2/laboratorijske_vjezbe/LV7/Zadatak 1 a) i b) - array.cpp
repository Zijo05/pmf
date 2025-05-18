//ZADATAK A I B - ARRAY

#include <iostream>
#include<string>
#include<vector>
#include <array>
#include<algorithm>
using namespace std;

bool  f(string s) {
      if (s.length()>3)   return true;
      return false;
  }

template <typename tip>
void podijeli(tip poc, tip kraj,  bool (*f)(string&), vector<string>&  v1, vector<string> &  v2) {
    for(auto it = poc; it!= kraj; it++)  {
        if (f(*it) ==true) v1.push_back(*it);
        else v2.push_back(*it);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}


int main(){

    array<string,5> niz;
    cout<<"Unesite rijeci"<<endl;
    string unos;
    for(int i=0; i< 5; i++) {
        getline(cin, unos);
        niz[i] = unos;
    }

    vector<string> v1;
    vector<string>  v2;

    podijeli(niz.begin(), niz.end(),[](string &s){ return s.length()>3;},  v1,   v2);
    for(int i=0; i< v1.size(); i++) cout<<v1[i]<<" ";
    cout<<endl;
    for(int i=0; i< v2.size(); i++) cout<<v2[i]<<" ";
    cout<<endl;
    return 0;
}


//ZADATAK G

#include <iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

bool  f(string s) {
      return s.length()>3;
  }

bool manji(string s1, string s2)  {
    int m = min(s1.length(), s2.length());
    int i=0;
    while (s1[i]==s2[i] && i<m)  i++;
    for (int j=i; i< m; j++) {
        if (toupper(s1[j]) < toupper(s2[j])) return true;
        else if (toupper(s1[j]) > toupper(s2[j]) ) return false;
    }
    return (s1.length() < s2.length());
    }



void sortiraj(vector<string*>& v)  {
    vector<string> pomocni;
    for(int i=0; i< v.size(); i++) pomocni.push_back(*(v[i]));
    sort(pomocni.begin(), pomocni.end(), manji);
    reverse(pomocni.begin(), pomocni.end());
    for(int i=0; i< v.size(); i++)  *(v[i])= pomocni[i];
}


void podijeli(vector<string*>& niz,  bool (*f)(string&), vector<string*> &v1,  vector<string*> &v2,
              vector<string>&  v3, void (*sortiraj)(vector<string*>&) ) {
    for(int i=0; i< niz.size(); i++)  {
        if (find(v3.begin(), v3.end(), *(niz[i])) == v3.end())  {
          if (f(*(niz[i])) ==true) v1.push_back(new string(*(niz[i])));
          else v2.push_back(new string(*(niz[i])));
         }
    }
    sortiraj(v1);
    sortiraj(v2);
}



int main(){

    vector<string*> niz;
    niz.push_back(new string("Abcde"));
    niz.push_back(new string("abcde"));
    niz.push_back(new string("zzzz"));
    niz.push_back(new string("efgh"));
    niz.push_back(new string("abcdef"));
    niz.push_back(new string("klmnop"));
    niz.push_back(new string("abc"));

    vector<string*> v1;
    vector<string*> v2;
    vector<string>  v3={"a", "b"};
    void (*g)(vector<string*>&) =  sortiraj;

    podijeli(niz,  [](string& s){ return s.length()> 3; },  v1, v2, v3, g);
    for(int i=0; i< v1.size(); i++) cout<<*v1[i]<<" ";
    cout<<endl;
    for(int i=0; i< v2.size(); i++) cout<<*v2[i]<<" ";
    cout<<endl;

    for(int i=0; i< v1.size(); i++) delete v1[i];
    for(int i=0; i< v1.size(); i++) delete v2[i];

    for(int i=0; i< niz.size(); i++) delete niz[i];

    return 0;
}



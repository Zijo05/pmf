//ZADATAK 1


#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool  f(string &s) {
      if (s.length()>3)  return true;
      return false;

  }

void podijeli(vector<string> &v, bool (*f)(string&), vector<string>&  v1, vector<string> &  v2) {
    for(int i=0; i< v.size(); i++)  {
        if (f(v[i])) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}


int main(){

    vector<string> v;
    vector<string> v1;
    vector<string>  v2;

    cout<<"Unosite riječi dok ne unesete KRAJ"<<endl;
    string unos;
    getline(cin, unos);
    while(unos != "KRAJ") {
        v.push_back(unos);
        getline(cin, unos);
    }

 //   for(int i=0; i< v.size(); i++) cout<<v[i]<<" ";
  //  cout<<endl;

    podijeli(v,  [](string &s){ return s.length()>3; } , v1,   v2);

    for(int i=0; i< v1.size(); i++) cout<<v1[i]<<" ";
    cout<<endl;
    for(int i=0; i< v2.size(); i++) cout<<v2[i]<<" ";

    return 0;
}

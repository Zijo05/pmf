
#include <iostream>
#include<cctype> // tolower toupper
#include<string>
#include<algorithm> // fja sort
using namespace std;


int brojRazlicitih(const string &s)  {
   int brojac=0;

   for(int i=0; i<s.length(); i++) {
    if ( ('a'<=s[i] and s[i]<='z')  or  ('A'<= s[i] and s[i]<= 'Z')) {
        bool nije_se_ranije_pojavio=true;
        for(int j=0;j<i;j++){
            if(tolower(s[i]) ==tolower(s[j]) ) {
                nije_se_ranije_pojavio = false;
                break;
            }

        }
        if (nije_se_ranije_pojavio) brojac++;
    }

   }
   return brojac;
}

bool f(const string& s1, const string &s2) {
     if(brojRazlicitih(s1)<brojRazlicitih(s2))  return true;
     if (brojRazlicitih(s1) > brojRazlicitih(s2) ) return false;
     return s1<s2;

}


int main(){

    int n;
    cin>>n;
    cin.ignore(10000, '\n');
    string* niz=new string[n];
    for(int i=0; i<n; i++)
        getline(cin, niz[i]);

    for(int i=0; i<n; i++)
         cout<<niz[i]<<" ";

    cout<<endl;
    sort(niz,niz+n, f );

    for(int i=0; i<n; i++) cout<<niz[i]<<" ";


}

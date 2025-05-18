//ZADATAK H

#include <iostream>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<algorithm>
using namespace std;

bool  f(string s) {
      if (s.length()>3) {  return true; }
      return false;
  }

bool manji(string s1, string s2)  {
    int m = min(s1.length(), s2.length());
    int i=0;
    while (s1[i]==s2[i] && i<m) i++;
    
    for (int j=i; i< m; j++) {
        if (toupper(s1[j])< toupper(s2[j])) return true;
        else if (toupper(s1[j]) > toupper(s2[j]) ) return false;
    }
    return (s1.length()< s2.length());   
    }


void sortiraj(list<string*> &v1, string s)  {
            list<string*>::iterator it = v1.begin();
            if (v1.size()==0) 
                v1.push_back(new string(s));
            else { 
                for (it = v1.begin();it != v1.end();it++)   
                        if (manji(s, *(*(it))) == true)  
                            break;
                    
                if  (it == v1.end())  v1.push_back(new string(s));
                else   v1.insert(it,  new string(s));   
            }
} 

void podijeli(string* niz, int n,  bool (*f)(string), list<string*> &v1, list<string*>  &v2,
              vector<string>  v3, void (*sortiraj)(list<string*>&, string) ) {
    
    for(int i=0; i< n; i++)  {
        if (find(v3.begin(), v3.end(), niz[i]) == v3.end())  {
        if (f(niz[i]) == true)    sortiraj(v1, niz[i]);  
        else  sortiraj(v2, niz[i]);
        }
    }
     reverse(v1.begin(), v1.end());
     reverse(v2.begin(), v2.end());
}


int main(){
    int n;
    cout<<"Unesite n"<<endl;
    cin>>n;

    string* niz = new string[n];
    string unos;
    cout<<"Unesite rijeci"<<endl;
    cin.ignore(10000, '\n');
    for(int i=0; i< n; i++) {
        getline(cin, unos);
        niz[i] = unos;    }

    list<string*> v1;
    list<string*> v2;
    vector<string> v3={"a", "b"};
   
    bool (*g)(string) =  f;
    void  (*h)(list<string*> &, string) = sortiraj;  
    podijeli(niz, n, g,  v1, v2, v3, sortiraj);
    cout<<endl;
    for (auto it = v1.begin(); it != v1.end(); ++it)
	      cout << *(*it)<<" "<< endl;
	      
    cout<<endl;
    
    for (auto it = v2.begin(); it != v2.end(); ++it)
	      cout << *(*it)<<" "<< endl;
	      
    cout<<endl;
    
    
    for (auto it = v1.begin(); it != v1.end(); ++it) {cout<<"brisem"<<endl; delete *it; }
    for (auto it = v2.begin(); it != v2.end(); ++it){ cout<<"brisem"<<endl;  delete *it; }
        
    delete[] niz;
    
    return 0;
}


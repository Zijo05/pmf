// pronaci broj pojkavljivanja 2,3,2 unutar niza

#include <iostream>
#include <vector>

using namespace std;

int zaprelaz(vector<int> &v, int p,int mid, int k){
    // 1 2 3| 2 4
    // 1 2 |3 2 
    int br=0;
    if(v[mid-1]==2 && v[mid]==3 && v[mid+1]==2) br++;
    if(v[mid]==2 && v[mid+1]==3 && v[mid+2]==2) br++;
    return br;
}

int funkcijaR(vector<int> &v, int p, int k){
    if(p==k || p == k-1) {
        return 0;
    }
    if(p==k-2) {
        if(v[p]==2 && v[p+1]==3 && v[p+2]==2){
            return 1;
        }
        else return 0;
    }

    auto mid = (k+p)/2;
    auto lijevo= funkcijaR(v, p, mid);
    auto desno = funkcijaR(v,mid+1, k);
    
    
    auto prelaz = zaprelaz(v, p, mid, k);
    auto suma = lijevo+desno+prelaz;
    return suma;
}

int funkcija(vector<int> &v){
    if(v.empty()) throw domain_error("Mrs napolje");
    return funkcijaR(v, 0, v.size()-1);
}

int main(){
    vector<int> v{1,2,3,4,2,3,2,3,2,4,9,2,3,2};
    auto rez = funkcija(v);
    cout<< "Broj ponavljanja: "<< rez;
    return 0;
}
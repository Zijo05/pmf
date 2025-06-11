#include<iostream>
#include<vector>
#include<algorithm> // fja sort
using namespace std;

template<typename tip>
tip* vratiSortiran(tip* niz, int n) {
     tip* rez = new tip[n]; 

     for(int i=0; i<n; i++)
        rez[i] = niz[i];

     sort(rez, rez + n);

     return rez; 

}


int main(){
    int niz[]= { 11,5,4,2,89,5,12};

    int* rez = vratiSortiran(&niz[0], 7); // ili vratiSortiran(niz,7)
    for(int i=0; i<7; i++) cout<<niz[i]<<" ";
    cout<<endl;
    for(int i=0; i<7; i++) cout<<rez[i]<<" ";
    cout<<endl;
    vector<int> v = {2, 1, 5, 4, 3};
    int *sortiraniV = vratiSortiran(&v[0], v.size());
    for(int i=0; i<v.size(); i++)  cout<<sortiraniV[i]<<" ";

}

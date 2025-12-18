#include <iostream>
#include <vector>
using namespace std;

//Napisati program koji metodom divide and conqeur nalazi najveći element u mxn matrici cijelih brojeva.
int maxElementRek(vector<vector<int>> &matrica, int r1, int r2, int c1, int c2){
    //bazni slučajevi
    if(r1>r2 || c1>c2) return 0;
    if(r1==r2 && c1==c2) return matrica[r1][c1];

    //rekurzija
    int sredinaR=(r1+r2)/2;
    int sredinaC=(c1+c2)/2;

    int gornjiLijevi=maxElementRek(matrica, r1, sredinaR, c1, sredinaC);
    int donjiLijevi=maxElementRek(matrica, sredinaR+1, r2, c1, sredinaC);
    int gornjiDesni=maxElementRek(matrica, r1, sredinaR, sredinaC+1, c2);
    int donjiDesni=maxElementRek(matrica, sredinaR+1, r2, sredinaC+1, c2);

    int maxLijevi=gornjiLijevi;
    if(donjiLijevi>maxLijevi) maxLijevi=donjiLijevi;
    int maxDesni=gornjiDesni;
    if(donjiDesni>maxDesni) maxDesni=donjiDesni;
    int ukupnoMax=max(maxLijevi, maxDesni);
    cout<<"Trenutno je sredina reda: "<<sredinaR<<", sredina kolone: "<<sredinaC<<", granice su ("<<r1<<","<<c1<<") i ("<<r2<<","<<c2<<") te je maksimalni element u tom dijelu matrice: "<<ukupnoMax<<endl;
    return ukupnoMax;
}

int maxElement(vector<vector<int>> &matrica){
    if(matrica.size()==0 || matrica[0].size()==0) return 0;
    return maxElementRek(matrica, 0, matrica.size()-1, 0, matrica[0].size()-1);
}

int main() {
    vector<vector<int>> matrica{
        {1, 2, 3},
        {5, 6, 32},
        {9, 110, 11},
        {13, 14, 15}
    };
    cout<<"Maksimalni element u matrici je: "<<maxElement(matrica)<<endl;
    return 0;
}
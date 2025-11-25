#include <iostream>
#include <vector>

using namespace std;

//Data je matrica dimenzija mxn. Potrebno je pronaći zbir svih elemenata koristeći divide and conquer algoritam.

int zbirMatriceRek(vector<vector<int>> &matrica, int r1, int r2, int c1, int c2){
    //bazni slučajevi
    if(r1>r2 || c1>c2){
        return 0;
    }
    if(r1==r2 && c1==c2){
        return matrica[r1][c1];
    }

    //rekurzija
    int sredinaR=(r1+r2)/2;
    int sredinaC=(c1+c2)/2;
    int gornjiLijevi=zbirMatriceRek(matrica, r1, sredinaR, c1, sredinaC);
    int donjiLijevi=zbirMatriceRek(matrica, sredinaR+1, r2, c1, sredinaC);
    int gornjiDesni=zbirMatriceRek(matrica, r1, sredinaR, sredinaC+1, c2);
    int donjiDesni=zbirMatriceRek(matrica, sredinaR+1, r2, sredinaC+1, c2);

    int zbir=gornjiLijevi + donjiLijevi + gornjiDesni + donjiDesni;
    cout<<"Trenutno je sredina reda: "<<sredinaR<<", sredina kolone: "<<sredinaC<<", granice su ("<<r1<<","<<c1<<") i ("<<r2<<","<<c2<<") te je zbir elemenata u tom dijelu matrice: "<<zbir<<endl;
    return zbir;
}

int zbirMatrice(vector<vector<int>> &matrica){
    if(matrica.size()==0 || matrica[0].size()==0) return 0;
    return zbirMatriceRek(matrica, 0, matrica.size()-1, 0, matrica[0].size()-1);
}

int main(){
    vector<vector<int>> v{
        {1, 2, 3, 8},
        {4, 5, 6, 0},
        {7, 8, 9, -4}
    };
    cout<<"Zbir svih elemenata matrice je: "<<zbirMatrice(v)<<endl;
    return 0;
}
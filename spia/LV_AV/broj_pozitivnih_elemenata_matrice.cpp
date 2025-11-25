#include <iostream>
#include <vector>

using namespace std;
//Divide and conquer algoritmom pronaći broj pozitivnih elemenata u mxn matrici cijelih brojeva.

int brojPozitivnihRek(vector<vector<int>> &matrica, int r1, int r2, int c1, int c2){
    //bazni slučajevi
    if(r1>r2 || c1>c2){
        return 0;
    }
    if(r1==r2 && c1==c2){
        if(matrica[r1][c1]>0){
            return 1;
        }
        else{
            return 0;
        }
    }

    //rekurzija
    int sredinaR=(r1+r2)/2;
    int sredinaC=(c1+c2)/2;
    int gornjiLijevi=brojPozitivnihRek(matrica, r1, sredinaR, c1, sredinaC);
    int donjiLijevi=brojPozitivnihRek(matrica, sredinaR+1, r2, c1, sredinaC);
    int gornjiDesni=brojPozitivnihRek(matrica, r1, sredinaR, sredinaC+1, c2);
    int donjiDesni=brojPozitivnihRek(matrica, sredinaR+1, r2, sredinaC+1, c2);

    int ukupnoPozitivnih=gornjiLijevi + donjiLijevi + gornjiDesni + donjiDesni;
    cout<<"Trenutno je sredina reda: "<<sredinaR<<", sredina kolone: "<<sredinaC<<", granice su ("<<r1<<","<<c1<<") i ("<<r2<<","<<c2<<") te je broj pozitivnih elemenata u tom dijelu matrice: "<<ukupnoPozitivnih<<endl;
    return ukupnoPozitivnih;
}

int brojPozitivnih(vector<vector<int>> &matrica){
    if(matrica.size()==0 || matrica[0].size()==0) return 0;
    return brojPozitivnihRek(matrica, 0, matrica.size()-1, 0, matrica[0].size()-1);
}

int main(){
    vector<vector<int>> v{
        {1, -2, 3, 8},
        {-4, 5, -6, 0},
        {7, -8, 9, -4}
    };
    cout<<"Broj pozitivnih elemenata u matrici je: "<<brojPozitivnih(v)<<endl;
    return 0;
}
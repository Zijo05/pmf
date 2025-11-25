#include <iostream>
#include <vector>
using namespace std;

//Napisati program koji metodom divide and conqeur nalazi najmanji element u mxn matrici cijelih brojeva.

int minElementRek(vector<vector<int>> &matrica, int r1, int r2, int k1, int k2){
    //bazni slučajevi
    if(r1>r2 || k1>k2){
        return INT_MAX;
    }
    if(r1==r2 && k1==k2){
        return matrica[r1][k1];
    }

    //rekurzija

    int sredinaR=(r1+r2)/2;
    int sredinaK=(k1+k2)/2;
    int gornjiLijevi=minElementRek(matrica, r1, sredinaR, k1, sredinaK);
    int donjiLijevi=minElementRek(matrica, sredinaR+1, r2, k1, sredinaK);
    int gornjiDesni=minElementRek(matrica, r1, sredinaR, sredinaK+1, k2);
    int donjiDesni=minElementRek(matrica, sredinaR+1, r2, sredinaK+1, k2);

    int minUkupno=min(min(gornjiLijevi, donjiLijevi), min(gornjiDesni, donjiDesni));
    return minUkupno;
}

int minElement(vector<vector<int>> &matrica){
    if(matrica.size()==0 || matrica[0].size()==0) return 0;
    return minElementRek(matrica, 0, matrica.size()-1, 0, matrica[0].size()-1);
}

void indeksNajmanjeg(vector<vector<int>> &matrica, int el, int &indeksR, int &indeksK){
    indeksR=-1;
    indeksK=-1;
    for(int i=0; i<matrica.size() && indeksR==-1; i++){
        for(int j=0; j<matrica[0].size(); j++){
            if(matrica[i][j]==el){
                indeksR=i;
                indeksK=j;
                break;
            }
        }
    }
}

int main(){
    vector<vector<int>> v{
        {4,8},
        {-3, 5},
        {1, 0},
    };
    int r, k;
    int minEl=minElement(v);
    indeksNajmanjeg(v, minEl, r, k);
    cout<<"Najmanji element u matrici je: "<<minEl<<endl;
    cout<<"Indeks najmanjeg elementa je: ("<<r<<","<<k<<")"<<endl;
    return 0;
}
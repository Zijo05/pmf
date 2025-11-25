#include <iostream>
#include <vector>

using namespace std;
//Pronaći da li je element a u mxn matrici koristeći divide and conquer.

int imaLiRek(vector<vector<int>> &matrica, int r1, int r2, int k1, int k2, int a){
    //bazni slučajevi
    if(r1>r2 || k1>k2){
        return 0;
    }
    if(r1==r2 && k1==k2){
        if(matrica[r1][k1]==a){
            return 1;
        }
        else return 0;
    }

    //rekurzija
    int sredinaR=(r1+r2)/2;
    int sredinaK=(k1+k2)/2;
    int gornjiLijevi=imaLiRek(matrica, r1, sredinaR, k1, sredinaK, a);
    int donjiLijevi=imaLiRek(matrica, sredinaR+1, r2, k1, sredinaK, a);
    int gornjiDesni=imaLiRek(matrica, r1, sredinaR, sredinaK+1, k2, a);
    int donjiDesni=imaLiRek(matrica, sredinaR+1, r2, sredinaK+1, k2, a);

    if(gornjiLijevi==1 || donjiLijevi==1 || gornjiDesni==1 || donjiDesni==1){
        return 1;
    }
    return 0;
}

int imaLi(vector<vector<int>> &matrica, int a){
    if(matrica.size()==0 || matrica[0].size()==0){
        return 0;
    }
    return imaLiRek(matrica, 0, matrica.size()-1, 0, matrica[0].size()-1, a);
}

int main(){
    vector<vector<int>> v{
        {1, -2, 3, 8},
        {-4, 5, -6, 0},
        {7, -8, 9, -4}
    };
    int a=10;
    int imaLiJe=imaLi(v, a);
    if(imaLiJe==1){
        cout<<"Element "<<a<<" se nalazi u matrici."<<endl;
    }
    else cout<<"Element "<<a<<" se ne nalazi u matrici."<<endl;
    return 0;
}
// pronaci broj pojavljivanja 2x2 matrica koje sadrze 4 petice unutar nxn matrice

#include <iostream>
#include <vector>

using namespace std;

int prelazi(vector<vector<int>> &v, int r1, int r2, int k1 ,int k2, int sredinaR, int sredinaK){
    int br=0;
    for (int i = r1; i < r2; i++){
        if(v[i][sredinaK]==5 && v[i][sredinaK+1]==5 && v[i+1][sredinaK]==5 && v[i+1][sredinaK+1]==5){
            br++;
        }
    }
    for (int j = k1; j < k2; j++)
    {
        if( v[sredinaR][j] == 5 && v[sredinaR][j+1] == 5 && v[sredinaR+1][j] == 5 && v[sredinaR+1][j+1] == 5) {
            br++;
        }
    }
    if(
        v[sredinaR][sredinaK] == 5 &&
        v[sredinaR][sredinaK+1] == 5 &&
        v[sredinaR+1][sredinaK] == 5 &&
        v[sredinaR+1][sredinaK+1] == 5 
    ) {
            br--;
    }
    return br;
}

int funkcijaR(vector<vector<int>> &v, int r1, int r2, int k1 ,int k2){
    if (r2 - r1 + 1 < 2 || k2 - k1 + 1 < 2) return 0;
    if(r1==r2-1 && k1==k2-1){
        if(v[r1][k1]==5 && v[r1][k2]==5 && v[r2][k1]==5 && v[r2][k2]==5) return 1;
    }

    auto sredinaR= (r2+r1)/2;
    auto sredinaK= (k2+k1)/2;

    auto gl = funkcijaR(v, r1, sredinaR, k1, sredinaK);
    auto dl = funkcijaR(v, sredinaR+1, r2 , k1, sredinaK);
    auto gd = funkcijaR(v, r1, sredinaR, sredinaK+1, k2);
    auto dd = funkcijaR(v, sredinaR+1, r2, sredinaK+1, k2);

    int ukupno = gl+dl+gd+dd;
    auto prelaz = prelazi(v, r1, r2, k1 ,k2 ,sredinaR, sredinaK);
    ukupno+= prelaz;
    return ukupno;
}


int funkcija(vector<vector<int>> &v){
    if(v.empty() || v[0].empty()) throw domain_error("Mrs napolje");
    return funkcijaR(v, 0, v.size()-1, 0, v[0].size()-1);
}

int main() {
    vector<vector<int>> v{
        {5,5,1,2,3},
        {5,5,4,5,5},
        {7,5,5,5,0},
        {5,5,5,3,1},
        {9,5,5,5,5}
    };

        
    auto rez = funkcija(v);
    cout<< "Broj ponavljanja: " << rez;
    return 0;
}
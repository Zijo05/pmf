#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;



bool kriterij(vector<int> v1, vector<int> v2)  {
   for (int i = 0; i < min(v1.size(), v2.size()); i++) {
    if (v1[i] < v2[i])
        return true;
    else if (v1[i] > v2[i])
        return false;
    }
    return v1.size() <= v2.size();
}




void Sortiraj(vector<vector<int>> &vektori)  {
    int n= vektori.size();
    vector<int> pomocni;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (kriterij(vektori[j], vektori[j + 1]) ==0) {
                pomocni = vektori[j];
                vektori[j]= vektori[j+1];
                vektori[j+1]= pomocni;
            }
}



int main (){

srand((unsigned) time(NULL));

vector<vector<int>> vektori;
for (int i=0; i< 1000; i++) {
   vector<int> pomocni;
   for (int j=0; j< 1000; j++)  {
      pomocni.push_back(rand() % 1000);
   }
   vektori.push_back(pomocni);
}

cout<<"Pocetak sortiranja "<<endl;
auto t0 = time(NULL);
Sortiraj(vektori);
auto t1 = time(NULL);
cout<<"Trajanje: "<<t1-t0<<"s"<<endl;

return 0;

}






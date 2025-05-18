
#include <iostream>
#include<vector>
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



void Sortiraj(vector<vector<int>> &vektori)  {//bubble sort
    int n= vektori.size();
    vector<int> pomocni;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++) //posljednjih i elemenata je vec sortirano
            if (kriterij(vektori[j], vektori[j + 1]) ==0) {
                pomocni = vektori[j];
                vektori[j]= vektori[j+1];
                vektori[j+1]= pomocni;
            }
}



int main (){

vector<int> v1{4,1,2};
vector<int> v2{4,1,2,0};
vector<int> v3{1,2};
cout<<kriterij(v1,v2)<<endl;
cout<<kriterij(v1,v3)<<endl;
cout<<kriterij(v2,v3)<<endl;


vector<vector<int>> vektori = {{5,4,3,21,1,0}, {1,2,3},{1,2,3,0},{5,4,2},{5,4,3,22,1,0}};
Sortiraj(vektori);

cout<<"Nakon sortiranja:" <<endl;
for (int i=0; i< vektori.size(); i++) {
  for (int j=0; j< vektori[i].size(); j++)  {
      cout<<vektori[i][j]<<" ";
  }
  cout<<endl;
}

return 0;
}



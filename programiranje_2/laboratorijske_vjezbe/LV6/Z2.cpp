#include <iostream>
#include<cctype> // tolower toupper
#include<string>
#include<algorithm> // fja sort
using namespace std;


/*
1 2 3   matrica
4 5 6
7 8 9


3 6 9   pomocna
2 5 8
1 4 7


*/

void rotiraj(int** mat, int n) {

    int** pomocna = new int*[n];
    for(int i=0; i<n; i++) pomocna[i]=new int[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
             pomocna[i][j] = mat[j][n-1-i];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat[i][j]=pomocna[i][j];


    for(int i=0; i<n; i++)
        delete[] pomocna[i];

    delete[] pomocna;


}


int main(){
    int n;
    cin>>n;
    cout<<"Unesi elemente"<<endl;
    int** matrica = new int*[n];
    for(int i=0; i<n; i++) matrica[i] = new int[n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        cin>>matrica[i][j];

    rotiraj(matrica, n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrica[i][j]<<" ";
        }
        cout<<endl;
    }



}


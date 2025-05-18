#include <iostream>
#include<string>
using namespace std;


void rotiraj(int** &mat, int n) {

    int** pomocna = new int*[n];
    for(int i=0; i<n; i++) pomocna[i]=new int[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
             pomocna[i][j] = mat[j][n-1-i];
        }
    }


    for(int i=0; i<n; i++)
        delete[] mat[i];

    delete[] mat;

    mat = pomocna;


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


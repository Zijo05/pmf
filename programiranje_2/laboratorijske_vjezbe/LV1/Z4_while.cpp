#include <iostream>
using namespace std;

int main() {

  int n;
  cin>>n;

  int i = 0;
  while(i < n) {
    int j = 0;
    while(j < n-1-i) {
        cout<<" ";
        j++;
    }
    j = 0;
    while(j < i+1) {
        cout<<"* ";
        j++;
    }
    i++;
    cout<<endl;
  }

  i = n - 2;
  while(i >= 0) {
    int j = 0;
    while(j < n-1-i) {
        cout<<" ";
        j++;
    }
    j = 0;
    while(j < i+1) {
        cout<<"* ";
        j++;
    }
    i--;
    cout<<endl;
  }

}

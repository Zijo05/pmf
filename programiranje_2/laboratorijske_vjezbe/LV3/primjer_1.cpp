#include<iostream>
using namespace std;


int main() {

int a[5] = {1,2,3,4,5};
int a1[]= {1,2,3,4};  // dim = 4
int b[5]= {} ; //  0,0,0,0,0

int c[5]= {3}; // 3,0,0,0,0

for(int i=0; i<5; i++)
    cout<<c[i]<<" ";
cout<<endl;


int d[20];
int n;
cin>>n;
for(int i=0; i<n; i++)  cin>>d[i];


bool isti = true;
for (int i=0; i<5; i++)
   if (a[i] != d[i] )  {
        isti = false;
        break;
   }
cout<<isti<<endl;

return 0;
}

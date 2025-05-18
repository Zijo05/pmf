#include<iostream>
#include<string>
#include<vector>
using namespace std;



int main(){
vector<int> a(12); // 0 0 0 0 0 0 0 0 0 0 0 0
cout<<a[2];

a.push_back(7);
for (int i=0; i<a.size(); i++)
     cout<<a[i]<<" ";

cout<<endl;

string s = "rijec";
s= "nova ";
cout<<s.length();
string b;
getline(cin,b);
cout<<b;


}

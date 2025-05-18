#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char a, b, c, d;
    char recenica[10]; // 9 znakova i NUL

    /*
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cout<<a<<b<<c<<d<<endl;
    */

    /*
    a= cin.get();
    b= cin.get();
    c= cin.get();
    d= cin.get();
    cout<<a<<b<<c<<d<<endl;
    */

    /*
    cin>>a;
    cin.ignore(10000, '\n');
    cin.getline(recenica, sizeof recenica);
    cout<<recenica;   // probati unijeti vise od 10 znakova
    cout<<strlen(recenica); // cstring
    */

    /*
    char dani[3][12]= {{'P','o','n'},{'U','t','o'},{'S','r','i'} };
    char dani2[3][12]= {"Pon", "Uto", "Sri" };
    cout<<dani2[1][1];

    */

    /*
    char novi[3][10];

    for (int i=0; i<3; i++)
        cin.getline(novi[i], 10);

    for (int i=0; i<3; i++)
        cout<<novi[i]<<" ";
    */

    return 0;
}

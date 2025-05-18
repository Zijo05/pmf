#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /* cout.width(8);
     cout<<555<<endl;
     cout<<setw(8)<<222<<setw(8)<<555<<endl;  */

    double a(0);
    double b(0);
    char znak = ' ';
    double rezultat(0);

    cout << "Unesite prvi broj ";
    cin >> a;
    cout << "Unesite drugi broj ";
    cin >> b;
    cout << "Unesite operaciju ";
    cin >> znak;

    if (znak == '+')
        rezultat = a + b;

    else if (znak == '-')
        rezultat = a - b;

    else if (znak == '*')
        rezultat = a * b;

    else if (znak == '/')
        rezultat = a / b;

    else
    {
        cout << "Znak nije ispravan" << endl;
        return 0;
    }

    cout << setw(7) << a << endl
         << setw(7) << b << " " << znak << endl
         << "--------" << endl
         << setw(7) << rezultat << endl;
    return 0;
}
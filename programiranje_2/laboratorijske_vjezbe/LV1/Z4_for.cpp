#include <iostream>
using namespace std;

int main()
{

  int n(0);

  cout << "Unesite prirodan broj n ";
  cin >> n;

  // trougao visine n
  for (int i = 1; i <= n; i++)
  {

    for (int k = 1; k <= n - i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
  // obrnuti trougao visine n-1
  for (int i = 1; i <= n - 1; i++)
  {

    for (int k = 1; k <= i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= n - i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

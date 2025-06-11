#include <iostream>
using namespace std;

void ispisi(int niz[][10], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << niz[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{

  int a[10][10];
  int n, m;
  cin >> m >> n;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  ispisi(a, m, n);

  int b[][2] = {{1, 2}, {2, 3}, {3, 4}};
  cout << b[0][1];
  return 0;
}

#include <iostream>
using namespace std;
/*
template <typename tip1, typename tip2> // moramo navesti za svaku fju
tip1 g(tip1 x, tip2 y)
{
  if (x > y)
    return x;
  return y;
}

template <typename tipRezultata, typename tip1, typename tip2>
tipRezultata f(tip1 x, tip2 y)
{
  if (x > y)
    return x;
  return y;
}
*/
template <typename rez, typename tip1, typename tip2>
rez fun(tip1 x, tip2 y)
{
  return x + y;
}

int main()
{

  /*cout << g(4, 5.7) << endl; // 5
  cout << g(5.7, 4) << endl; // 5.7

  cout << g<int, double>(5.7, 4) << endl; // 5
  cout << g<double, int>(5.7, 4) << endl; // 5.7

  double a(5.7);
  int b(3);
  cout << f<int>(a, b) << endl;    // 5
  cout << f<double>(a, b) << endl; // 5.7

  cout << f<int, int, double>(2, 2.3) << endl;

  cout << f<double, int, int>(2, 5.3) << endl;
  */
  cout << fun<long double>(2.5L, 2LL);
}
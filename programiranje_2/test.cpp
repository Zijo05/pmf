#include <iostream>
#include <vector>
#include <algorithm>

template <typename Ispisiviobjekat>
void IspisiNiz(std::vector<Ispisiviobjekat> v, int broj_elemenata)
{
    for (int i = 0; i < broj_elemenata; i++)
        std ::cout << v[i] << " ";
}

int main()
{
    std::vector<double> v{1.2, 2, 3, 4, 5, 6, 7};
    std::sort(v.begin(), v.end(), std::greater<double>());
    IspisiNiz(v, 7);
    return 0;
}
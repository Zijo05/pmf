#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &v)
{
    if (v.size() <= 1)
    {
        return;
    }
    if (v.size() == 2)
    {
        if (v[0] > v[1])
        {
            swap(v[0], v[1]);

            return;
        }
    }

    vector<int> prvi;
    vector<int> drugi;

    auto srednji = v.size() / 2;
    for (size_t i = 0; i < srednji; i++)
    {
        prvi.push_back(v[i]);
    }
    for (size_t i = srednji; i < v.size(); i++)
    {
        drugi.push_back(v[i]);
    }
    merge_sort(prvi);
    merge_sort(drugi);

    size_t i = 0, j = 0, k = 0;
    while (i < prvi.size() && j < drugi.size())
    {
        if (prvi[i] < drugi[j])
        {
            v[k] = prvi[i];
            i++;
        }
        else
        {
            v[k] = drugi[j];
            j++;
        }
        k++;
    }

    while (i < prvi.size())
    {
        v[k] = prvi[i];
        i++;
        k++;
    }

    while (j < drugi.size())
    {
        v[k] = drugi[j];
        j++;
        k++;
    }
}

int main()
{
    vector<int> v{5, 3, 8, 6, 2, 7, 4, 1};
    cout << "Prije sortiranja: ";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Nakon sortiranja: ";
    merge_sort(v);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
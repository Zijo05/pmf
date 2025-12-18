#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertionSort(vector<T> &v)
{
    for (int i(1); i < v.size(); i++)
    {
        T trenutni = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > trenutni)
        {
            swap(v[j], v[j + 1]);
            j--;
        }
    }
}

int main()
{
    vector<int> v = {9, 5, 7, 2, 3, 0, 1, 6, 4, 8};
    insertionSort(v);
    for (const auto &el : v)
        cout << el << " ";

    return 0;
}
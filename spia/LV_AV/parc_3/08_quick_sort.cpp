#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T> &v, int low, int high)
{
    int pivot_idx = (low + high) / 2;
    T pivot = v[pivot_idx];
    std::swap(v[pivot_idx], v[high]);
    int border = low;
    for (int i(low); i < high; i++)
    {
        if (v[i] < pivot)
        {
            std::swap(v[i], v[border]);
            border++;
        }
    }
    std::swap(v[border], v[high]);

    return border;
}

template <typename T>
void quick_sort(std::vector<T> &v, int low, int high)
{
    if (low < high)
    {
        int pivot_idx = partition(v, low, high);

        quick_sort(v, low, pivot_idx - 1);
        quick_sort(v, pivot_idx + 1, high);
    }
}

int main()
{
    std::vector<int> v{9, 5, 6, 4, 1, 7, 8, 2, 3};

    quick_sort(v, 0, v.size() - 1);

    for (auto &el : v)
        std::cout << el << " ";

    return 0;
}
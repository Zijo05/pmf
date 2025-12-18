#include <iostream>
#include <vector>

template <typename T>
void bubble_sort(std::vector<T> &v)
{
    int n(v.size());
    for (int i(0); i < n; i++)
        for (int j(0); j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
}

template <typename T>
void selection_sort(std::vector<T> &v)
{
    int n(v.size());
    for (int i(0); i < n - 1; i++)
    {
        int smallest_unsorted_idx(i);
        for (int j(i + 1); j < n; j++)
            if (v[j] < v[smallest_unsorted_idx])
                smallest_unsorted_idx = j;
        std::swap(v[i], v[smallest_unsorted_idx]);
    }
}

template <typename T>
void insertion_sort(std::vector<T> &v)
{
    int n(v.size());
    for (int i(1); i < n; i++)
        for (int j(i - 1); j >= 0 && v[j] > v[j + 1]; j--)
            std::swap(v[j], v[j + 1]);
}

template <typename T>
void merge_sort(std::vector<T> &v, int start, int end)
{
    if (v.empty())
        throw std::invalid_argument("Vector is empty!");
    else if (start >= end)
        return;
    else if (end - start == 1)
    {
        std::swap(v[start], v[end]);
        return;
    }

    int middle = (start + end) / 2;
    merge_sort(v, start, middle);
    merge_sort(v, middle + 1, end);

    int i(start), j(middle + 1);
    std::vector<T> temporary_v;
    while (i <= middle && j <= end)
    {
        if (v[i] < v[j])
        {
            temporary_v.push_back(v[i]);
            i++;
        }
        else
        {
            temporary_v.push_back(v[j]);
            j++;
        }
    }

    while (i <= middle)
    {
        temporary_v.push_back(v[i]);
        i++;
    }
    while (j <= end)
    {
        temporary_v.push_back(v[j]);
        j++;
    }

    int counter(0);
    for (i = start; i <= end; i++)
    {
        v[i] = temporary_v[counter];
        counter++;
    }
}

template <typename T>
void merge_sort(std::vector<T> &v) { merge_sort(v, 0, v.size() - 1); }

template <typename T>
int partition(std::vector<T> &v, int start, int end)
{
    int pivot_idx = (start + end) / 2;
    T pivot = v[pivot_idx];

    std::swap(v[end], v[pivot_idx]);
    int border = start;
    for (int i(start); i < end; i++)
    {
        if (v[i] < pivot)
        {
            std::swap(v[i], v[border]);
            border++;
        }
    }
    std::swap(v[border], v[end]);
    return border;
}

template <typename T>
void quick_sort(std::vector<T> &v, int start, int end)
{
    if (start < end)
    {
        int pivot_idx = partition(v, start, end);

        quick_sort(v, start, pivot_idx - 1);
        quick_sort(v, pivot_idx + 1, end);
    }
}

template <typename T>
void quick_sort(std::vector<T> &v) { quick_sort(v, 0, v.size() - 1); }

template <typename T>
void shell_sort(std::vector<T> &v)
{
    int n(v.size());
    for (int gap(n / 2); gap > 0; gap /= 2)
        for (int i(gap); i < n; i++)
            for (int j(i); j >= gap && v[j] < v[j - gap]; j -= gap)
                std::swap(v[j], v[j - gap]);
}

int nCifra(int number, int n) // returns n-th digit of a number
{
    int count(0);
    while (n - 1 > 0)
    {
        number /= 10;
        n--;
    }
    return number % 10;
}

void radix_sort(std::vector<int> &v, int maxDigits)
{
    int digitPosition = 1;
    for (int i(0); i < maxDigits; i++)
    {
        std::vector<std::vector<int>> boxes(10);
        for (const auto &number : v)
        {
            int digit = nCifra(number, digitPosition);
            boxes[digit].push_back(number);
        }

        v.clear();
        for (const auto &box : boxes)
            for (const auto &number : box)
                v.push_back(number);
        digitPosition++;
    }
}

int findDigitHex(int number, int n) // returns n-th hex digit of a number
{
    return (number >> (4 * n) & 0x0F);
}

void radix_sort_hex(std::vector<int> &v, int maxDigits)
{
    int digitPosition = 1;
    for (int i(0); i < maxDigits; i++)
    {
        std::vector<std::vector<int>> boxes(16);
        for (const auto &number : v)
        {
            int digit = findDigitHex(number, digitPosition);
            boxes[digit].push_back(number);
        }

        v.clear();
        for (const auto &box : boxes)
            for (const auto &number : box)
                v.push_back(number);
        digitPosition++;
    }
}
int main()
{
    std::vector<int> v1{9, 5, 6, 4, 1, 7, 8, 2, 3, 0};
    std::vector<int> v2{123, 13, 52, 24, 567, 21, 34, 264, 124, 35, 456, 19, 757, 22};

    // bubble_sort(v1);
    // selection_sort(v1);
    // insertion_sort(v1);
    // merge_sort(v1);
    // quick_sort(v1);
    // shell_sort(v1);
    // radix_sort(v1, 1);
    // radix_sort_hex(v2, 3); // Ne radi

    for (auto &el : v2)
        std::cout
            << el << " ";

    return 0;
}
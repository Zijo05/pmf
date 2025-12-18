#include <iostream>
#include <vector>
#include <algorithm>

int ternarySum(const std::vector<int> &arr, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    if (left == right)
    {
        return arr[left];
    }

    int size = right - left + 1;
    int part_size = size / 3;

    int mid1 = left + part_size - 1;
    int mid2 = left + 2 * part_size - 1;

    // The array is logically split into three parts:
    // Part 1: [left, mid1]
    // Part 2: [mid1 + 1, mid2]
    // Part 3: [mid2 + 1, right]

    int sum1 = ternarySum(arr, left, mid1);
    int sum2 = ternarySum(arr, mid1 + 1, mid2);
    int sum3 = ternarySum(arr, mid2 + 1, right);

    return sum1 + sum2 + sum3;
}

int findArraySum(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        return 0;
    }
    return ternarySum(arr, 0, arr.size() - 1);
}

int main()
{
    std::vector<int> myArray = {1, 5, 3, 8, 2, 9, 4, 7, 6};
    int totalSum = findArraySum(myArray);
    std::cout << "The sum of the array elements is: " << totalSum << std::endl;

    std::vector<int> emptyArray = {};
    int emptySum = findArraySum(emptyArray);
    std::cout << "The sum of the empty array elements is: " << emptySum << std::endl;

    return 0;
}
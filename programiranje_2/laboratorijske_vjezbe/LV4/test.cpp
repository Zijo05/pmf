#include <iostream>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    ptr = ptr + 1;

    std::cout << *ptr;

    return 0;
}
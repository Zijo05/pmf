#include <iostream>
#include <vector>

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

int findDigitHex(int number, int n) // returns n-th hex digit of a number
{
    return (number >> (4 * n) & 0x0F);
}

void radixSort(std::vector<int> &v, int maxDigits)
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

void radixSortHex(std::vector<int> &v, int maxDigits)
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
    std::vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(v, 3);
    for (const auto &el : v)
        std::cout << el << " ";

    std::cout << "\n";
    std::vector<int> vHex = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSortHex(vHex, 3);
    for (const auto &el : vHex)
        std::cout << el << " ";

    return 0;
}
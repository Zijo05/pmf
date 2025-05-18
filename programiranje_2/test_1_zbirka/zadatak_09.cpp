#include <iostream>

int main()
{
    unsigned int n;
    std::cout << "Unesi n: ";
    std::cin >> n;

    if (n == 1)
        std::cout << "1";
    else
    {
        unsigned int i(2);
        while (n != 1)
        {
            if (n % i == 0)
            {
                std::cout << i << " ";
                n /= i;
            }
            else
                i++;
        }
    }

    return 0;
}
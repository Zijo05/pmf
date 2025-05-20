#include <iostream>
#include <cmath>

bool je_prost(unsigned int n)
{
    if (n == 1)
        return false;
    for (unsigned int i(2); i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    std::cout << je_prost(2);

    return 0;
}
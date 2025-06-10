#include <iostream>

bool je_pitagorina_trojka(unsigned int a, unsigned int b, unsigned int c)
{
    return a * a + b * b == c * c;
}

void ispisiKombinacije(const int &n)
{
    if (n <= 0)
        throw std::domain_error("Uneseni broj nije prirodan!");
    std::cout << "a b c\n";
    for (unsigned int i(2); i < n; i++)
        for (unsigned int j(i + 1); j < n; j++)
            for (unsigned int k(j + 1); k <= n; k++)
                if (je_pitagorina_trojka(i, j, k))
                    std::cout << i << " " << j << " " << k << std::endl;
}

int main()
{
    int n;
    std::cout << "Unesi n: ";
    std::cin >> n;

    try
    {
        ispisiKombinacije(n);
    }
    catch (const std::domain_error &e)
    {
        std::cout << e.what();
    }
    return 0;
}
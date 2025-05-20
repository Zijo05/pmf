#include <iostream>
#include <set>

template <typename T>
std::set<T> SimetricnaRazlika(const std::set<T> &A, const std::set<T> &B)
{
    std::set<T> rezultat;
    for (const auto &x : A)
        if (B.find(x) == B.end())
            rezultat.insert(x);
    for (const auto &x : B)
        if (A.find(x) == A.end())
            rezultat.insert(x);
    return rezultat;
}

int main()
{
    unsigned int na, nb;
    std::cout << "Unesite broj clanova skupa A: ";
    std::cin >> na;
    std::set<int> A;
    std::cout << "Unesite clanove skupa A: ";
    for (unsigned int i(0); i < na; i++)
    {
        int x;
        std::cin >> x;
        A.insert(x);
    }

    std::cout << "Unesite broj clanova skupa B: ";
    std::cin >> nb;
    std::set<int> B;
    std::cout << "Unesite clanove skupa B: ";
    for (unsigned int i(0); i < nb; i++)
    {
        int x;
        std::cin >> x;
        B.insert(x);
    }

    std::set<int> C = SimetricnaRazlika(A, B);
    std::cout << "Simetricna razlika skupa A i B: ";
    for (const auto &x : C)
        std::cout << x << " ";

    return 0;
}
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> najduzi_monotoni_podniz(const std::vector<T> &v)
{
    std::vector<T> trenutni_podniz;
    std::vector<T> najveci_podniz;

    bool opada = true;
    for (unsigned int i(0); i < v.size(); i++)
    {
        if (opada && (trenutni_podniz.empty() || trenutni_podniz.back() >= v[i]))
        {
            trenutni_podniz.push_back(v[i]);
        }
        else if (opada)
        {
            if (trenutni_podniz.size() > najveci_podniz.size())
            {
                najveci_podniz = trenutni_podniz;
            }
            trenutni_podniz.clear();
            trenutni_podniz.push_back(v[i - 1]);
            trenutni_podniz.push_back(v[i]);
            opada = false;
        }

        if (!opada && (trenutni_podniz.empty() || trenutni_podniz.back() <= v[i]))
        {
            trenutni_podniz.push_back(v[i]);
        }
        else if (!opada)
        {
            if (trenutni_podniz.size() > najveci_podniz.size())
            {
                najveci_podniz = trenutni_podniz;
            }
            trenutni_podniz.clear();
            trenutni_podniz.push_back(v[i - 1]);
            trenutni_podniz.push_back(v[i]);
            opada = true;
        }
    }

    if (trenutni_podniz.size() > najveci_podniz.size())
    {
        najveci_podniz = trenutni_podniz;
    }

    return najveci_podniz;
}

int main()
{
    std::vector<int> v = {3, 6, 7, 5, 2, 4, 8, 9, 8, 8, 5, 3, 2, 4, 9, 9, 7, 1};
    std::vector<int> podniz = najduzi_monotoni_podniz(v);
    std::cout << "Najduzi monotoni podniz: ";
    for (const auto &el : podniz)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    v = {3, 6, 7, 5, 2, 4, 8, 15, 14, 13, 12, 11, 7, 9, 8, 8, 5, 3, 2, 4, 9, 9, 7, 1};
    podniz = najduzi_monotoni_podniz(v);
    std::cout << "Najduzi monotoni podniz: ";
    for (const auto &el : podniz)
    {
        std::cout << el << " ";
    }
    return 0;
}

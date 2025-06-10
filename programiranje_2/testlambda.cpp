#include <iostream>
#include <functional>

double funkcija(double arg)
{
    return arg * 2;
}

std::function<double(double)> testf(std::function<double(double)> funkcijaufunkciji)
{
    return [funkcijaufunkciji](double x)
    {
        return funkcijaufunkciji(x * x);
    };
}

int main()
{
    std::cout << testf([](double arg)
                       { return arg * 2; })(2.5);

    return 0;
}
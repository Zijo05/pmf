#include <iostream>
#include <functional>

double fun1(double y)
{
    return 2.5;
}

double fun2(double x)
{
    return x * 2;
}

std::function<double(double)> fun(std::function<double(double)> f1, std::function<double(double)> f2)
{

    return [f1, f2](double x)
    { return f2((f1(x))); };
}

int main()
{
    fun(fun1, fun2);
    return 0;
}
#include <iostream>
#include <new>

int main()
{
    try
    {
        while (true)
        {
            new int[100000000ul]; // Attempt to allocate a large amount of memory
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "Allocation failed: " << e.what() << '\n'; // Catch the exception and print the error message
    }
}
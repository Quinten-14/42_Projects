#include "./main.h"
#include <cctype>
#include <cstdlib>

void    printChar(char& c)
{
    std::cout << c << ' ';
}

void    toUpper(char &arr)
{
    arr = std::toupper(static_cast<char>(arr));
}

int     main(void)
{
    char arr[] = {'a', 'b', 'c'};

    ::iter(arr, sizeof(arr) / sizeof(char), printChar);
    std::cout << std::endl;

    ::iter(arr, sizeof(arr) / sizeof(char), toUpper);
    ::iter(arr, sizeof(arr) / sizeof(char), printChar);
}

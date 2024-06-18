#include "./main.h"
#include <cstdlib>

void    printChar(char& c) {
    std::cout << c << ' ';
}

int     main(void)
{
    char arr[] = {'a', 'b', 'c'};

    ::iter(arr, sizeof(arr) / sizeof(char), printChar);
    std::cout << std::endl;
}

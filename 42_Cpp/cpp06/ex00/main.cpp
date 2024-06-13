#include "./main.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong Input. Should be a char/ int/ float/ double" << std::endl;
        return 0;
    }

    ScalarConverter::convert(av[1]);
    return 0;
}

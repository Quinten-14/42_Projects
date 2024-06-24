#include "./class/RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong input found. Should be ./RPN '2 1 +' for example\n";
        exit(EXIT_SUCCESS);
    }

    try
    {
        RPN     rpn;
        double result = rpn.caculateResultRPN(av[1]);
        std::cout << "Result: " << result << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

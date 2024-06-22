#include <cstdlib>
#include <iostream>
#include "./class/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Wrong parameter input. Must be ./btc 'InputFile'\n";
        return (EXIT_SUCCESS);
    }

    BitcoinExchange bitcoinExchange;

    bitcoinExchange.calculateBtcWorthFromFile(av[1]);
}

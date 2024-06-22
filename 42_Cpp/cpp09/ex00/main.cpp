#include <iostream>
#include "./class/BitcoinExchange.hpp"

int main(void)
{
    BitcoinExchange bitcoinExchange;

    std::string testDate = "2011-01-03";

    float   price = bitcoinExchange.getPrice(testDate);

    std::cout << price << std::endl;

    std::cout << bitcoinExchange.calculateTotalPrice(price, 3) << std::endl;
}

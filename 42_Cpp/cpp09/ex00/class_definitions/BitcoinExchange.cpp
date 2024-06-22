// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#include "../class/BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{
    populateMapWithCsvData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange&    BitcoinExchange::operator = (const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->historyChart = other.historyChart;
    }
    return (*this);
}

std::ifstream   BitcoinExchange::openCsvFile(void) const
{
    std::ifstream   file("data/data.csv");
    if (!file.is_open())
    {
        std::cerr << "Could not open the data file\n";
        exit(EXIT_FAILURE);
    }
    return file;
}

time_t  BitcoinExchange::parseToDate(const std::string& dateStr) const
{
    std::tm tm = {};
    std::istringstream  ss(dateStr);

    ss >> std::get_time(&tm, "%Y-%m-%d");
    return std::mktime(&tm);
}

void    BitcoinExchange::parseCsvLine(const std::string& line)
{
    std::istringstream  ss(line);
    std::string dateStr, priceStr;

    std::getline(ss, dateStr, ',');
    std::getline(ss, priceStr, ',');

    time_t  date = parseToDate(dateStr);
    float   price = std::atof(priceStr.c_str());

    this->historyChart[date] = price;
}

void    BitcoinExchange::populateMapWithCsvData(void)
{
    std::ifstream   file = openCsvFile();
    std::string     line;

    // Skips the header line at the beginning of csv file
    std::getline(file, line);

    while (std::getline(file, line))
        parseCsvLine(line);
    file.close();
}

std::map<time_t, float>::const_iterator BitcoinExchange::findClosestDate(time_t date) const
{
    std::map<time_t, float>::const_iterator it = historyChart.find(date);
    int     dayInSeconds = 86400;

    while (it == historyChart.end() && date > 0)
    {
        date -= dayInSeconds;
        it = historyChart.find(date);
    }

    return it;
}


float   BitcoinExchange::getPrice(const std::string& dateStr) const
{
    time_t  date = parseToDate(dateStr);
    std::map<time_t, float>::const_iterator it = findClosestDate(date);

    if (it != historyChart.end())
        return it->second;

    return -1;
}

float   BitcoinExchange::calculateTotalPrice(const float price, const float amountBtc) const
{
    if (price == -1)
        return (std::cerr << "Price not available for the given date.\n", -1);
    return amountBtc * price;
}

BitcoinExchange::~BitcoinExchange()
{

}

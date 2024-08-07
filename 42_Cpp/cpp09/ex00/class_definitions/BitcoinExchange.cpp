// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#include "../class/BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
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
        this->historyChart = other.historyChart;
    return (*this);
}

std::ifstream& BitcoinExchange::openCsvFile(std::ifstream& file) const
{
    file.open("data/data.csv");
    
    if (!file.is_open())
    {
        std::cerr << "Could not open the data file\n";
        exit(EXIT_FAILURE);
    }

    return file;
}

time_t BitcoinExchange::parseToDate(const std::string& dateStr) const
{
    std::tm tm = {};
    if (strptime(dateStr.c_str(), "%Y-%m-%d", &tm) == NULL)
        return -1;
    return std::mktime(&tm);
}

void BitcoinExchange::parseCsvLine(const std::string& line)
{
    std::istringstream ss(line);
    std::string dateStr, priceStr;

    std::getline(ss, dateStr, ',');
    std::getline(ss, priceStr, ',');

    time_t date = parseToDate(dateStr);
    float price = std::atof(priceStr.c_str());

    this->historyChart[date] = price;
}

void BitcoinExchange::populateMapWithCsvData(void)
{
    std::ifstream file;
    openCsvFile(file);
    std::string line;

    // Skips the header line at the beginning of csv file
    std::getline(file, line);

    while (std::getline(file, line))
        parseCsvLine(line);
    file.close();
}

std::map<time_t, float>::const_iterator BitcoinExchange::findClosestDate(time_t date) const
{
    std::map<time_t, float>::const_iterator it = historyChart.find(date);
    int dayInSeconds = 86400;

    while (it == historyChart.end() && date > 0)
    {
        date -= dayInSeconds;
        it = historyChart.find(date);
    }

    return it;
}

float BitcoinExchange::getPriceSingleBtc(const std::string& dateStr) const
{
    time_t date = parseToDate(dateStr);
    if (date == -1)
        throw DateInvalid();
    std::map<time_t, float>::const_iterator it = findClosestDate(date);

    if (it != historyChart.end())
        return it->second;

    return -1;
}

float BitcoinExchange::calculateTotalPrice(const float price, const float amountBtc) const
{
    if (price == -1)
        return (-1);
    return amountBtc * price;
}

std::ifstream& BitcoinExchange::openInputFile(const std::string filePath, std::ifstream& file) const
{
    file.open(filePath.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error found with opening input file\n";
        exit(EXIT_FAILURE);
    }

    return file;
}

std::string BitcoinExchange::extractDateFromInput(const std::string& line) const
{
    std::istringstream ss(line);
    std::string dateStr;

    std::getline(ss, dateStr, '|');

    dateStr.erase(dateStr.find_last_not_of(" \n\r\t") + 1);

    return dateStr;
}

float BitcoinExchange::extractValueFromInput(const std::string& line) const
{
    std::istringstream ss(line);
    std::string dateStr, valueStr;

    std::getline(ss, dateStr, '|');
    std::getline(ss, valueStr, '|');

    valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);

    float value = std::atof(valueStr.c_str());
    if (value < 0 || value > 1000)
        throw ValueInvalid();
    return value;
}

void BitcoinExchange::calculateBtcWorthFromFile(const std::string filePath)
{
    std::ifstream file;
    openInputFile(filePath, file);
    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        try
        {
            std::string date = extractDateFromInput(line);
            float amountBtc = extractValueFromInput(line);
            float TotalWorth = calculateTotalPrice(getPriceSingleBtc(date), amountBtc);

            if (TotalWorth == -1)
            {
                std::cout << "On " << date << ", price not available" << std::endl;
                continue;
            }


            std::cout << "On " << date << ", the worth of " << amountBtc << " btc was " << TotalWorth << std::endl;
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

const char* BitcoinExchange::DateInvalid::what() const throw()
{
    return "Date is invalid";
}

const char* BitcoinExchange::ValueInvalid::what() const throw()
{
    return "Value is invalid";
}

BitcoinExchange::~BitcoinExchange()
{

}


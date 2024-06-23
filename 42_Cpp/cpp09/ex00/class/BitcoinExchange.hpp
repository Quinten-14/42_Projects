// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream>
#include <map>
#include <sstream>
class   BitcoinExchange
{
    public:
        BitcoinExchange();
 
        BitcoinExchange(const BitcoinExchange& other);

        BitcoinExchange&    operator = (const BitcoinExchange& other);
        
        void            calculateBtcWorthFromFile(const std::string filePath);

        class   DateInvalid: public std::exception {
            virtual const char* what() const throw();
        };
        
        class   ValueInvalid: public std::exception {
            virtual const char* what() const throw();
        };

        ~BitcoinExchange();
    private:
        std::map<time_t, float> historyChart;

    private:
        std::ifstream   openCsvFile(void) const;
        time_t          parseToDate(const std::string& dateStr) const;
        void            parseCsvLine(const std::string& line);
        void            populateMapWithCsvData(void);
        float           getPriceSingleBtc(const std::string& dateStr) const;
        float           calculateTotalPrice(const float price, const float amountBtc) const;
        std::string          extractDateFromInput(const std::string& line) const;
        float           extractValueFromInput(const std::string& line) const;
        std::ifstream   openInputFile(const std::string filePath) const;
        std::map<time_t, float>::const_iterator findClosestDate(time_t date) const;
};

#endif


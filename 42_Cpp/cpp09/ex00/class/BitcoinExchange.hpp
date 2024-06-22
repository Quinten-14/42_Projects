// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream>
#include <map>
class   BitcoinExchange
{
    public:
        BitcoinExchange();
 
        BitcoinExchange(const BitcoinExchange& other);

        BitcoinExchange&    operator = (const BitcoinExchange& other);
        
        float           getPrice(const std::string& dateStr) const;

        ~BitcoinExchange();
    private:
        std::map<time_t, float> historyChart;

    private:
        std::ifstream   openCsvFile(void) const;
        time_t          parseToDate(const std::string& dateStr) const;
        void            parseCsvLine(const std::string& line);
        void            populateMapWithCsvData(void);
        std::map<time_t, float>::const_iterator findClosestDate(time_t date) const;
};

#endif


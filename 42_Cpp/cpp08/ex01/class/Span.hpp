#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>

class   Span
{
    public:
        Span(unsigned int n);

        void    addNumber(int number);

        int     shortestSpan();

        int     longestSpan();

        class   LimitReachedException : public std::exception {
            virtual const char* what() const throw();
        };

        class   NoSpanPossibleException : public std::exception {
            virtual const char* what() const throw();
        };

    private:
        unsigned int    m_length;
        std::vector<int>    m_numbers;
};

#endif

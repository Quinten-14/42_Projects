#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

class   Span
{
    public:
        Span(unsigned int n);

        Span(const Span& other);

        Span&   operator = (const Span& other);

        void    addNumber(int number);

        int     shortestSpan();

        template <typename Iterator>
        void    addNumbers(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) + m_numbers.size() > m_length)
                throw LimitReachedException();
            m_numbers.insert(m_numbers.end(), begin, end);
        }

        int     longestSpan();

        class   LimitReachedException : public std::exception {
            virtual const char* what() const throw();
        };

        class   NoSpanPossibleException : public std::exception {
            virtual const char* what() const throw();
        };

        ~Span();

    private:
        unsigned int    m_length;
        std::vector<int>    m_numbers;
};

#endif

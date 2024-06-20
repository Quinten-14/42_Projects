#include "../class/Span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Span::Span(unsigned int n) : m_length(n), m_numbers(std::vector<int>()) {}

const char* Span::LimitReachedException::what() const throw()
{
    return "Vector has reached the limit";
}

Span::Span(const Span& other)
{
    m_length = other.m_length;
    m_numbers.clear();
    m_numbers = other.m_numbers;
}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        m_length = other.m_length;
        m_numbers = other.m_numbers;
    }
    return (*this);
}

void    Span::addNumber(int number)
{
    if (m_numbers.size() < m_length)
    {
        m_numbers.push_back(number);
        std::cout << "Succesfully added number " << number << " to the vector" << std::endl;
    }
    else
        throw LimitReachedException();
}

const char* Span::NoSpanPossibleException::what() const throw()
{
    return "No span could be found";
}

int     Span::shortestSpan(void)
{
    if (m_numbers.size() < 2)
        throw NoSpanPossibleException();
    std::vector<int>    sortedVector(m_numbers);
    std::sort(sortedVector.begin(), sortedVector.end());
    int shortest = sortedVector[1] - sortedVector[0];
    for (int i = 1; i < sortedVector.size() - 1; ++i)
    {
        int span = sortedVector[i + 1] - sortedVector[i];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int     Span::longestSpan(void)
{
    if (m_numbers.size() < 2)
        throw NoSpanPossibleException();

    int min = *std::min_element(m_numbers.begin(), m_numbers.end());
    int max = *std::max_element(m_numbers.begin(), m_numbers.end());

    return max - min;
}

Span::~Span() {}

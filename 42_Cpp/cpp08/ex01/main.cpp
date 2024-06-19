#include "./class/Span.hpp"
#include <exception>
#include <iostream>

int     main(void)
{
    Span    span(5);

    try
    {
        span.addNumber(10);
        span.addNumber(20);
        span.addNumber(0);
        span.addNumber(100);
        std::cout << "Largest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

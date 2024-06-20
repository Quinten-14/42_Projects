#include "./class/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int main() {
    Span span(5);

    try {
        span.addNumber(10);
        span.addNumber(20);
        span.addNumber(0);
        span.addNumber(100);

        std::cout << "Largest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

        // Adding a range of numbers
        std::vector<int> additionalNumbers;
        additionalNumbers.push_back(30);
        additionalNumbers.push_back(40);
        span.addNumbers(additionalNumbers.begin(), additionalNumbers.end());

        std::cout << "Added more numbers successfully." << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Span largeSpan(100000);
        std::vector<int> largeNumbers;
        srand(time(NULL));
        for (int i = 0; i < 100000; ++i) {
            largeNumbers.push_back(rand() % 1000000);
        }

        largeSpan.addNumbers(largeNumbers.begin(), largeNumbers.end());

        std::cout << "Largest span in largeSpan: " << largeSpan.longestSpan() << std::endl;
        std::cout << "Shortest span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

// Subject test

/*
int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
return 0; }
*/

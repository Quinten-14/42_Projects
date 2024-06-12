#include "./main.h"
#include <exception>

int main(void)
{
    std::cout << "<--- Constructors --->" << std::endl;
    
    try {
        Bureaucrat  jeffrey("jeffrey", 1);
        std::cout << jeffrey;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat  jeffrey("jeffrey", -5);
        std::cout << jeffrey;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat  jeffrey("jeffrey", 500);
        std::cout << jeffrey;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "<--- Increment --->" << std::endl;

    try {
        Bureaucrat  jeffrey("jeffrey", 14);
        std::cout << jeffrey;
        jeffrey.incrementGrade();
        std::cout << jeffrey;
        jeffrey.incrementGrade(5);
        std::cout << jeffrey;
        jeffrey.incrementGrade(10);
        std::cout << jeffrey;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "<--- Decrement --->" << std::endl;

    try {
        Bureaucrat  jeffrey("jeffrey", 14);
        std::cout << jeffrey;
        jeffrey.decrementGrade();
        std::cout << jeffrey;
        jeffrey.decrementGrade(5);
        std::cout << jeffrey;
        jeffrey.decrementGrade(140);
        std::cout << jeffrey;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

#include "./main.h"
#include <exception>

int main(void)
{
    std::cout << "\n<--- Constructors --->\n" << std::endl;
    
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

    std::cout << "\n<--- Increment --->\n" << std::endl;

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

    std::cout << "\n<--- Decrement --->\n" << std::endl;

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

    std::cout << "\n<--- Signing Forms (Success) --->\n" << std::endl;

    try {
        Form    build_plan("build_plan", 50, 50);

        std::cout << build_plan;

        Bureaucrat  jeffrey("jeffrey", 10);
        
        jeffrey.signForm(build_plan);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n<--- Signing Forms (Too Low Grade) --->\n" << std::endl;

    try {
        Form    build_plan("build_plan", 50, 50);

        std::cout << build_plan;

        Bureaucrat  jeffrey("jeffrey", 70);
        
        jeffrey.signForm(build_plan);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n<--- Signing Forms (Out Of Range) --->\n" << std::endl;

    try {
        Form    build_plan("build_plan", 0, 0);
        Form    renovation_plan("renovation_plan", 200, 200);

        std::cout << build_plan;

        Bureaucrat  jeffrey("jeffrey", 10);
        
        jeffrey.signForm(build_plan);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

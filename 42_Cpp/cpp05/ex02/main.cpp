#include "./main.h"
#include "class/RobotomyRequestForm.hpp"
#include "class/ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat jeffrey("Jeffrey", 150);

    try
    {
        ShrubberyCreationForm   main_form("home");
        jeffrey.signForm(main_form);
        jeffrey.executeForm(main_form);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

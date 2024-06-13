#include "./main.h"
#include "class/Bureaucrat.hpp"
#include "class/PresidentialPardonForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include <exception>

int main(void)
{
    std::cout << "<--- Basic Tests --->\n" << std::endl;

    Bureaucrat  jeffrey("Jeffrey", 1);

    std::cout << "-- Shrubbery Creation (Success) --\n" << std::endl;
    ShrubberyCreationForm   form("home");
    jeffrey.signForm(form);
    jeffrey.executeForm(form);

    std::cout << "\n-- Robotomy Request (Success) --\n" << std::endl;
    RobotomyRequestForm     robot_creation_form("Frank");
    jeffrey.signForm(robot_creation_form);
    jeffrey.executeForm(robot_creation_form);

    std::cout << "\n-- Presidential Pardon (Success) --\n" << std::endl;
    PresidentialPardonForm  pardon_form("Sorry");
    jeffrey.signForm(pardon_form);
    jeffrey.executeForm(pardon_form);

    std::cout << "\n-- Form Not Signed (Fail) --\n" << std::endl;
    RobotomyRequestForm     not_signed("Not Signed Test");
    try
    {
        jeffrey.executeForm(not_signed);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "<--- Bureaucrat Grade Test --->\n" << std::endl;

    std::cout << "-- Too High Grade Test --\n" << std::endl;
    try
    {
        Bureaucrat  john("John", 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-- Too Low Grade Test --\n" << std::endl;
    try
    {
        Bureaucrat  john("John", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-- Too Low Grade To Sign Test --\n" << std::endl;
    try
    {
        Bureaucrat  john("John", 140);
        RobotomyRequestForm Robot("Frank");

        john.signForm(Robot);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-- Too Low Grade To Execute Test --\n" << std::endl;
    try
    {
        Bureaucrat  john("John", 70);
        RobotomyRequestForm Robot("Frank");

        john.signForm(Robot);
        john.executeForm(Robot);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

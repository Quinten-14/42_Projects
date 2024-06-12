#include "./main.h"
#include "class/Bureaucrat.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include <exception>

int main(void)
{
    Bureaucrat  jeffrey("Jeffrey", 1);

    ShrubberyCreationForm   form("home");
    jeffrey.signForm(form);
    jeffrey.executeForm(form);

    RobotomyRequestForm     robot_creation_form("Frank");
    jeffrey.signForm(robot_creation_form);
    jeffrey.executeForm(robot_creation_form);
}

#include "./main.h"
#include "class/Bureaucrat.hpp"
#include "class/PresidentialPardonForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include <exception>

int main() {
    Intern intern;
    Bureaucrat jeffrey("Jeffrey", 1);

    Form* form1 = intern.makeForm("shrubbery creation", "home");
    jeffrey.signForm(*form1);
    jeffrey.executeForm(*form1);
    if (form1)
        delete form1;

    Form* form2 = intern.makeForm("robotomy request", "Frank");
    if (form2)
        delete form2;

    Form* form3 = intern.makeForm("presidential pardon", "Sorry");
    if (form3)
        delete form3;

    Form* form4 = intern.makeForm("unknown form", "Target");
    if (form4)
        delete form4;

    return 0;
}

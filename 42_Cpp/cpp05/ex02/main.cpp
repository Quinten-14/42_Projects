#include "./main.h"
#include "class/Bureaucrat.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include <exception>

int main(void)
{
    Bureaucrat  jeffrey("Jeffrey", 1);

    ShrubberyCreationForm   form("home");
    jeffrey.signForm(form);
    jeffrey.executeForm(form);
}

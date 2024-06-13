#include "../main.h"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other) {}
    return *this;
}

Form* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    if (formName == "shrubbery creation")
        return (std::cout << "Intern creates " << formName << std::endl, new ShrubberyCreationForm(target));
    else if (formName == "robotomy request")
        return (std::cout << "Intern creates " << formName << std::endl, new RobotomyRequestForm(target));
    else if (formName == "presidential pardon")
        return (std::cout << "Intern creates " << formName << std::endl, new PresidentialPardonForm(target));
    else
        throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "<intern> Form not found!";
}

Intern::~Intern() {}

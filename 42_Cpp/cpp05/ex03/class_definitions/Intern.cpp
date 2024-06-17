#include "../main.h"

Intern::Intern() {
    m_names[0] = "shrubbery creation";
    m_names[1] = "robotomy request";
    m_names[2] = "presidential pardon";

    m_forms[0] = &Intern::makeShrubberyCreationForm;
    m_forms[1] = &Intern::makeRobotomyRequestForm;
    m_forms[2] = &Intern::makePresidentialPardonForm;
} 

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            m_names[i] = other.m_names[i];
            m_forms[i] = other.m_forms[i];
        }
    }
    return *this;
}

Form* Intern::makeShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

Form* Intern::makePresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    for (int i = 0; i < 3; i++)
        if (m_names[i] == formName)
            return (std::cout << "Intern creates " << formName << std::endl, m_forms[i](target));
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "<intern> Form not found!";
}

Intern::~Intern() {}

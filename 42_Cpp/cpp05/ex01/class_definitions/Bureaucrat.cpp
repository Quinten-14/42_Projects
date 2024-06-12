#include "../main.h"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name), m_grade(grade)
{
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    else if (grade < MAX_GRADE)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : m_name(other.m_name), m_grade(other.m_grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        m_grade = other.m_grade;
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return m_name;
}

int Bureaucrat::getGrade() const
{
    return m_grade;
}

void Bureaucrat::incrementGrade(int change)
{
    if (m_grade - change < MAX_GRADE)
        throw GradeTooHighException();
    m_grade -= change;
}

void Bureaucrat::decrementGrade(int change)
{
    if (m_grade + change > MIN_GRADE)
        throw GradeTooLowException();
    m_grade += change;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low!";
}

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream &output, const Bureaucrat& bureaucrat)
{
    output << bureaucrat.getName() << ", bureaucrat of grade " << bureaucrat.getGrade() << std::endl;
    return output;
}

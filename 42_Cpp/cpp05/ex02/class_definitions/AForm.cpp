#include "../main.h"

AForm::AForm() : m_requiredToSign(0), m_requiredToExec(0) {}

AForm::AForm(const std::string& name, const std::string& target, int gradeRequiredSign, int gradeRequiredExec) : m_name(name), m_target(target), m_isSigned(false), m_requiredToSign(gradeRequiredSign), m_requiredToExec(gradeRequiredExec) {
    if (this->m_requiredToSign > MIN_GRADE)
        throw AForm::GradeTooLowException();
    else if (this->m_requiredToSign < MAX_GRADE)
        throw AForm::GradeTooHighException();
    
    if (this->m_requiredToExec > MIN_GRADE)
        throw AForm::GradeTooHighException();
    else if (this->m_requiredToExec < MAX_GRADE)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other) : m_name(other.m_name), m_isSigned(false), m_requiredToSign(other.m_requiredToSign), m_requiredToExec(other.m_requiredToExec) {}

AForm& AForm::operator=(const AForm& other)
{
    // The if here seems useless
    //if (this != &other) {}
    return *this;
}

const std::string& AForm::getName() const
{
    return this->m_name;
}

bool AForm::isSignedGetter() const
{
    return this->m_isSigned;
}

int AForm::gradeRequiredSignGetter() const
{
    return this->m_requiredToSign;
}

int AForm::gradeRequiredExecGetter() const
{
    return this->m_requiredToExec;
}

const std::string& AForm::getTarget() const
{
    return this->m_target;
}

void AForm::beSigned(const Bureaucrat& Bureaucrat)
{
    if (m_requiredToSign < Bureaucrat.getGrade())
        throw GradeTooLowException();
    this->m_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!this->m_isSigned)
        throw NotSignedException();
    if (this->m_requiredToExec < executor.getGrade())
        throw GradeTooLowException();
    executeConcrete();
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!\n";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm is not yet signed!\n";
}

std::ostream& operator << (std::ostream &output, const AForm& form)
{
    output << "AForm " << form.getName() << " Signed: " << form.isSignedGetter() << " Grade Required To Sign: " << form.gradeRequiredSignGetter() << " Grade Required To Execute: " << form.gradeRequiredExecGetter() << std::endl;
    return output;
}

AForm::~AForm() {}

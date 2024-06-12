#include "../main.h"

Form::Form() : m_requiredToSign(0), m_requiredToExec(0) {}

Form::Form(const std::string& name, const std::string& target, int gradeRequiredSign, int gradeRequiredExec) : m_name(name), m_target(target), m_isSigned(false), m_requiredToSign(gradeRequiredSign), m_requiredToExec(gradeRequiredExec) {
    if (this->m_requiredToSign > MIN_GRADE)
        throw Form::GradeTooLowException();
    else if (this->m_requiredToSign < MAX_GRADE)
        throw Form::GradeTooHighException();
    
    if (this->m_requiredToExec > MIN_GRADE)
        throw Form::GradeTooHighException();
    else if (this->m_requiredToExec < MAX_GRADE)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& other) : m_name(other.m_name), m_isSigned(false), m_requiredToSign(other.m_requiredToSign), m_requiredToExec(other.m_requiredToExec) {}

Form& Form::operator=(const Form& other)
{
    // The if here seems useless
    //if (this != &other) {}
    return *this;
}

const std::string& Form::getName() const
{
    return this->m_name;
}

bool Form::isSignedGetter() const
{
    return this->m_isSigned;
}

int Form::gradeRequiredSignGetter() const
{
    return this->m_requiredToSign;
}

int Form::gradeRequiredExecGetter() const
{
    return this->m_requiredToExec;
}

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
    if (m_requiredToSign < Bureaucrat.getGrade())
        throw GradeTooLowException();
    this->m_isSigned = true;
}

void Form::execute(const Bureaucrat& executor) const
{
    if (!this->m_isSigned)
        throw NotSignedException();
    if (this->m_requiredToExec < executor.getGrade())
        throw GradeTooLowException();
    executeConcrete();
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade too low!";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade too high!";
}

const char* Form::NotSignedException::what() const throw()
{
    return "Form: form is not yet signed!";
}

std::ostream& operator << (std::ostream &output, const Form& form)
{
    output << "Form " << form.getName() << " Signed: " << form.isSignedGetter() << " Grade Required To Sign: " << form.gradeRequiredSignGetter() << " Grade Required To Execute: " << form.gradeRequiredExecGetter() << std::endl;
    return output;
}

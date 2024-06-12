#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "./Form.hpp"

class   Bureaucrat
{
    public:
        //Constructors
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);

        // Copy Constructor
        Bureaucrat(const Bureaucrat& other);

        // Copy Assignment Operator
        Bureaucrat& operator = (const Bureaucrat& other);

        // Name Getter
        const std::string& getName() const;

        // Grade Getter
        int getGrade() const;

        // Increment Grade by one (default)
        void incrementGrade(int change = 1);

        // Decrement Grade by one (default)
        void decrementGrade(int change = 1);

        // Sign Form
        void signForm(Form& form) const;

        class GradeTooLowException: public std::exception {
            virtual const char* what() const throw();
        };
        
        class GradeTooHighException: public std::exception {
            virtual const char* what() const throw();
        };

        // Destructor
        ~Bureaucrat();

    private:
        const std::string m_name;
        int m_grade;
};

std::ostream& operator<<(std::ostream &output, const Bureaucrat& bureaucrat);

#endif

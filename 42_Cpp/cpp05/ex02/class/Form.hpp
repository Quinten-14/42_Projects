#ifndef FORM_HPP
# define FORM_HPP

class   Bureaucrat;

class   Form
{
    public:
        // Constructor
        Form();
        Form(const std::string& name, const std::string& target, int gradeRequiredSign, int gradeRequiredExec);

        // Copy Constructor
        Form(const Form& other);

        // Copy Assignment Operator
        Form& operator = (const Form& other);

        // Name Getter
        const std::string& getName() const;

        // isSigned Getter
        bool isSignedGetter() const;

        // Grade Required To Sign Getter
        int gradeRequiredSignGetter() const;

        // Grade Required To Execute Getter
        int gradeRequiredExecGetter() const;

        // Sign Form Function
        void beSigned(const Bureaucrat& Bureaucrat);

        // Execute Form
        void execute(const Bureaucrat& executor) const;

        class GradeTooLowException: public std::exception {
            virtual const char* what() const throw();
        };

        class GradeTooHighException: public std::exception {
            virtual const char* what() const throw();
        };

        class NotSignedException: public std::exception {
            virtual const char* what() const throw();
        };


    private:
        const std::string m_name;
        const std::string m_target;
        bool m_isSigned;
        const int m_requiredToSign;
        const int m_requiredToExec;

    private:
        virtual void executeConcrete() const = 0;
};

std::ostream& operator<<(std::ostream &output, const Form& form);

#endif

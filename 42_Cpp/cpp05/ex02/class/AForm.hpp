#ifndef AFORM_HPP
# define AFORM_HPP

class   Bureaucrat;

class   AForm
{
    public:
        // Constructor
        AForm();
        AForm(const std::string& name, const std::string& target, int gradeRequiredSign, int gradeRequiredExec);

        // Copy Constructor
        AForm(const AForm& other);

        // Copy Assignment Operator
        AForm& operator = (const AForm& other);

        // Name Getter
        const std::string& getName() const;

        // isSigned Getter
        bool isSignedGetter() const;

        // Grade Required To Sign Getter
        int gradeRequiredSignGetter() const;

        // Grade Required To Execute Getter
        int gradeRequiredExecGetter() const;

        // Target Getter
        const std::string& getTarget() const;

        // Sign AForm Function
        void beSigned(const Bureaucrat& Bureaucrat);

        // Execute AForm
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

        virtual ~AForm();


    private:
        const std::string m_name;
        const std::string m_target;
        bool m_isSigned;
        const int m_requiredToSign;
        const int m_requiredToExec;

    private:
        virtual void executeConcrete() const = 0;
};

std::ostream& operator<<(std::ostream &output, const AForm& form);

#endif

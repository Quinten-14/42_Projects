#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
    public:
        // Constructor
        Intern();

        // Copy Constructor
        Intern(const Intern& other);

        // Copy Assignment
        Intern& operator=(const Intern& other);

        // Destructor
        ~Intern();

        Form* makeForm(const std::string& formName, const std::string& target) const;

        class FormNotFoundException: public std::exception {
            virtual const char* what() const throw();
        };

    private:
        std::string m_names[3];
        Form*   (*m_forms[3])(const std::string& target);

        static Form* makeShrubberyCreationForm(const std::string& target);
        static Form* makeRobotomyRequestForm(const std::string& target);
        static Form* makePresidentialPardonForm(const std::string& target);
};

#endif

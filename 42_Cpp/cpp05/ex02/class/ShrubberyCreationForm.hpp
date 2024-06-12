#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "./Form.hpp"

class   ShrubberyCreationForm : public Form
{
    public:
        // Constructors
        ShrubberyCreationForm(const std::string& target);

        // Copy Constructor
        ShrubberyCreationForm(const ShrubberyCreationForm& other);

        // Copy Assignment
        ShrubberyCreationForm& operator = (const ShrubberyCreationForm& other);

        // Destructor
        ~ShrubberyCreationForm();

    private:
        const std::string m_target;

        // Private because doesn't require one param like subject says
        ShrubberyCreationForm();

        void executeConcrete() const;
};

#endif

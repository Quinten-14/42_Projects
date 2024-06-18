#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"

class   ShrubberyCreationForm : public AForm
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
        // Private because doesn't require one param like subject says
        ShrubberyCreationForm();

        void executeConcrete() const;
};

#endif

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        // Constructors
        PresidentialPardonForm(const std::string& target);

        // Copy Constructor
        PresidentialPardonForm(const PresidentialPardonForm& other);

        // Copy Assignment
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        // Destructor
        ~PresidentialPardonForm();

    private:
        // Private because  doesn't require one param like subject asks
        PresidentialPardonForm();

        void executeConcrete() const;
};

#endif

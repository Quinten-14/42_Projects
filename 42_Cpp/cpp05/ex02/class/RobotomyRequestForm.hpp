#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        // Constructors
        RobotomyRequestForm(const std::string& target);

        // Copy Constructor
        RobotomyRequestForm(const RobotomyRequestForm& other);

        // Copy Assignment
        RobotomyRequestForm& operator = (const RobotomyRequestForm& other);

        // Destructor
        ~RobotomyRequestForm();

    private:
        // private because doesn't require one param like subject asks
        RobotomyRequestForm();

        void executeConcrete() const;
};

#endif

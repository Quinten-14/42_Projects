#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "./Form.hpp"

class RobotomyRequestForm : public Form
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

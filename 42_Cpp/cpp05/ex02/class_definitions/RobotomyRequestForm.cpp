#include "../main.h"

RobotomyRequestForm::RobotomyRequestForm(): AForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {}
    return *this;
}

void RobotomyRequestForm::executeConcrete() const 
{
    std::cout << "* DRILLING NOISES AT 6AM *" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->getTarget() << " is succesfully turned into a robot" << std::endl;
    else
        std::cout << this->getTarget() << " failed to turn into a robot, big skill issue" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

#include "../main.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {}
    return *this;
}

void PresidentialPardonForm::executeConcrete() const
{
    std::cout << this->getTarget() << " was pardoned by Zaphod Beeblebrox!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

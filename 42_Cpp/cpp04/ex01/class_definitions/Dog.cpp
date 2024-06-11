#include "../main.h"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog Object Created" << std::endl;
    this->type = "Dog";
    this->m_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Object Copied" << std::endl;
    this->m_brain = new Brain();
    *this = other;
}

Dog& Dog::operator = (const Dog& other)
{
    std::cout << "Dog Assignment Copied" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        //if (other.m_brain)
            //delete other.m_brain;
        //this->m_brain = new Brain();
        *(this->m_brain) = *(other.m_brain);
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woef" << std::endl;
}

void Dog::setIdea(std::string idea, int i)
{
    if (i <= 100)
    {
        this->m_brain->ideaSetter(idea, i);
        return ;
    }
    std::cerr << "Error: Ideas can't be more then 100" << std::endl;
}

std::string Dog::getIdea(int i) const
{
    if (i <= 100)
        return (*this->m_brain->ideaGetter(i));
    std::cerr << "Error: Ideas can't be more then 100" << std::endl;
    return ("");
}

Brain* Dog::getBrainAddress(void) const
{
    return (this->m_brain);
}

Dog::~Dog(void)
{
    delete this->m_brain;
    std::cout << "Dog Object Destroyed" << std::endl;
}

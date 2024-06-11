#include "../main.h"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat Object Created" << std::endl;
    this->type = "Cat";
    this->m_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Object Copied" << std::endl;
    this->m_brain = new Brain();
    *this = other;
}

Cat& Cat::operator = (const Cat& other)
{
    std::cout << "Cat Assignment Copied" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        if (other.m_brain)
            delete other.m_brain;
        this->m_brain = new Brain();
        *(this->m_brain) = *(other.m_brain);
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}

void Cat::setIdea(std::string idea, int i)
{
    if (i <= 100)
    {
        this->m_brain->ideaSetter(idea, i);
        return ;
    }
    std::cerr << "Error: Ideas can't be more then 100" << std::endl;
}

std::string Cat::getIdea(int i) const
{
    if (i <= 100)
        return (*(this->m_brain->ideaGetter(i)));
    std::cerr << "Error: Ideas can't be more then 100" << std::endl;
    return ("");
}

Brain* Cat::getBrainAddress(void) const
{
    return (this->m_brain);
}

Cat::~Cat(void)
{
    delete this->m_brain;
    std::cout << "Cat Object Destroyed" << std::endl;
}

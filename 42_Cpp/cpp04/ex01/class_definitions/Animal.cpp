#include "../main.h"

// Constructor
Animal::Animal(void)
{
    std::cout << "Animal object created" << std::endl;
    this->type = "";
}

// Copy Constructor
Animal::Animal(const Animal& other)
{
    std::cout << "Animal object copied" << std::endl;
    *this = other;
}

// Copy Assignment
Animal& Animal::operator = (const Animal& other)
{
    std::cout << "Animal Assignment Copied" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

// Type getter
std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Wind Whistling" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal Object Destroyed" << std::endl;
}

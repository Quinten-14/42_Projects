#include "../main.h"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "Wrong Animal Object Created" << std::endl;
    this->type = "wrong";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "Wrong Animal Object Copied" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other)
{
    std::cout << "Wrong Animal Assignment Copied" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Wind Whistling" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "Wrong Animal Object Destroyed" << std::endl;
}

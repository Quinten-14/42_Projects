#include "../main.h"

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "Wrong Cat Object Created" << std::endl;
    this->type = "Definetly Not A Cat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "Wrong Cat Object Copied" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator = (const WrongCat& other)
{
    std::cout << "Wrong Cat Assignment Copied" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Woew" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "Wrong Cat Object Destroyed" << std::endl;
}

#include "../main.h"

// Constructor
Brain::Brain(void)
{
    std::cout << "Created Brain Object" << std::endl;
}

// Copy Constructor
Brain::Brain(const Brain& other)
{
    std::cout << "Copied Brain Object" << std::endl;
    *this = other;
}

Brain& Brain::operator = (const Brain& other)
{
    std::cout << "Copied Brain Assignment" << std::endl;
    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->m_ideas[i] = other.m_ideas[i];
    return (*this);
}

// Setter
void    Brain::ideaSetter(std::string idea, int i)
{

    if (i <= 100)
        this->m_ideas[i] = idea;
    else
        std::cerr << "Error: Ideas can't be more then 100" << std::endl;
}

// Getter
const std::string*  Brain::ideaGetter(int i)
{
    if (i <= 100)
        return(&(this->m_ideas[i]));
    std::cerr << "Error: Ideas can't be more then 100" << std::endl;
    return (static_cast<const std::string*>(NULL));
}

// Destructor
Brain::~Brain(void)
{
    std::cout << "Brain Object Destroyed" << std::endl;
}

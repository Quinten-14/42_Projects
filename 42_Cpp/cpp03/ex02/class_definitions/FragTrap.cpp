#include "../main.h"

// Constructor without name
FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "Created FragTrap object without a name" << std::endl;
    this->m_name = "";
    this->m_hit_points = 100;
    this->m_energy_points = 100;
    this->m_attack_damage = 30;
}

// Constructor with name
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Created FragTrap object with name: " << name << std::endl;
    this->m_name = name;
    this->m_hit_points = 100;
    this->m_energy_points = 100;
    this->m_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Copied FragTrap object" << std::endl;
    *this = other;
}

FragTrap&   FragTrap::operator = (const FragTrap& other)
{
    std::cout << "Copied FragTrap assignment" << std::endl;
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit_points = other.m_hit_points;
        this->m_energy_points = other.m_energy_points;
        this->m_attack_damage = other.m_attack_damage;
    }
    return (*this);
}

void    FragTrap::HighFivesGuys(void)
{
    if (this->m_hit_points <= 0)
        std::cout << "High Fiver: " << this->m_name << " is already dead" << std::endl;
    else if (this->m_energy_points <= 0)
        std::cout << "High Fiver: " << this->m_name << " has no energy left" << std::endl;
    else
    {
        this->m_energy_points -= 1;
        std::cout << "High Fiver: " << this->m_name << " gave you a high five" << std::endl;
    }
}

FragTrap::~FragTrap(void)
{
    std::cout << "Destroyed ScavTrap object with name " << m_name << std::endl;
}

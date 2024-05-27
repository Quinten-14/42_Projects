#include "../main.h"
#include <iostream>

// Constructor without name
ClapTrap::ClapTrap(void)
{
    std::cout << "Created ClapTrap object without a name" << std::endl;
    this->m_name = "";
    this->m_hit_points = 10;
    this->m_energy_points = 10;
    this->m_attack_damage = 10;
}


// Constructor with name
ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Created ClapTrap object with name: " << name << std::endl;
    this->m_name = name;
    this->m_hit_points = 10;
    this->m_energy_points = 10;
    this->m_attack_damage = 10;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copied ClapTrap object" << std::endl;
    *this = other;
}

// Copy assignment overloader
ClapTrap&   ClapTrap::operator = (const ClapTrap& other)
{
    std::cout << "Copied ClapTrap assignment" << std::endl;
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit_points = other.m_hit_points;
        this->m_energy_points = other.m_energy_points;
        this->m_attack_damage = other.m_attack_damage;
    }
    return (*this);
}

// Attack
void    ClapTrap::attack(const std::string& target)
{
    if (this->m_hit_points <= 0)
    {
        std::cout << "Attack: " << this->m_name << " is already dead" << std::endl;
        return ;
    }
    if (this->m_energy_points <= 0)
    {
        std::cout << "Attack: " << this->m_name << " has no energy left" << std::endl;
        return ;
    }
    std::cout << "Attack: " << this->m_name << " takes a swing at " << target << std::endl;
    this->m_energy_points -= 1;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "Damager: " << m_name << " takes " << amount << " hit points worth of damage" << std::endl;
    this->m_hit_points -= amount;
    if (this->m_hit_points <= 0)
        std::cout << "Damager: " << m_name << " has been killed" << std::endl;
    else
        std::cout << "Damager: " << m_name << " has " << m_hit_points <<  " amount of health left" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->m_hit_points <= 0)
    {
        std::cout << "Repair: " << this->m_name << " is already dead" << std::endl;
        return ;
    }
    if (this->m_energy_points <= 0)
    {
        std::cout << "Repair: " << this->m_name << " has no energy left" << std::endl;
        return ;
    }
    this->m_hit_points += amount;
    this->m_energy_points -= 1;
    std::cout << "Repair: " << m_name << " repaired itself and now has " << m_hit_points << " hit points and " << m_energy_points << " energy left" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destroyed ClapTrap object with name " << m_name << std::endl;
}

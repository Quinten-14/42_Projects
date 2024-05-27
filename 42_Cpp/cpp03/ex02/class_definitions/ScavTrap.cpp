#include "../main.h"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "Created ScavTrap object without a name" << std::endl;
    this->m_name = "";
    this->m_hit_points = 100;
    this->m_energy_points = 50;
    this->m_attack_damage = 20;
    this->m_in_guard_mode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Created ScavTrap object with name: " << name << std::endl;
    this->m_name = name;
    this->m_hit_points = 100;
    this->m_energy_points = 50;
    this->m_attack_damage = 20;
    this->m_in_guard_mode = false;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "Copied ScavTrap object" << std::endl;
    *this = other;
}

ScavTrap&   ScavTrap::operator = (const ScavTrap& other)
{
    std::cout << "Copied ScavTrap assignment" << std::endl;
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit_points = other.m_hit_points;
        this->m_energy_points = other.m_energy_points;
        this->m_attack_damage = other.m_attack_damage;
        this->m_in_guard_mode = other.m_in_guard_mode;
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->m_hit_points <= 0)
        std::cout << "Attack: " << this->m_name << " is already dead" << std::endl;
    else if (this->m_energy_points <= 0)
        std::cout << "Attack: " << this->m_name << " has no energy left" << std::endl;
    else
    {
        std::cout << "Attack: " << this->m_name << " stomps on " << target << std::endl;
        this->m_energy_points -= 1;
    }
}

void    ScavTrap::guardGate(void)
{
    if (this->m_hit_points <= 0)
        std::cout << "Guard Mode: " << this->m_name << " is already dead" << std::endl;
    else if (this->m_energy_points <= 0)
        std::cout << "Guard Mode: " << this->m_name << " has no enery left" << std::endl;
    else if (this->m_in_guard_mode == true)
        std::cout << "Guard Mode: " << this->m_name << " is already in Guard Mode" << std::endl;
    else
    {
        this->m_energy_points -= 1;
        std::cout << "Guard Mode: " << this->m_name << " entered Guard Mode" << std::endl;
    }
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destroyed ScavTrap object with name " << m_name << std::endl;
}

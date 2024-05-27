#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class   ScavTrap : public ClapTrap
{
    public:
        // Constructors
        ScavTrap(void);
        ScavTrap(std::string name);

        // Copy Constructor
        ScavTrap(const ScavTrap& other);

        // Copy Assignment
        ScavTrap& operator = (const ScavTrap& other);

        // Attack
        void    attack(const std::string& target);

        // Gate keeper mode
        void    guardGate(void);

        ~ScavTrap(void);
    private:
        bool    m_in_guard_mode;
};

#endif

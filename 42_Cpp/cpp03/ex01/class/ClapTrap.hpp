#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class   ClapTrap
{
    public:
        // Constructors
        ClapTrap(void);
        ClapTrap(std::string name);

        // Copy Constructor
        ClapTrap(const ClapTrap& other);

        // Copy Assignment
        ClapTrap& operator = (const ClapTrap& other);

        // Attack
        void    attack(const std::string& target);

        // Take damage
        void    takeDamage(unsigned int amount);

        // beRepaired
        void    beRepaired(unsigned int amount);

        // Destructor
        ~ClapTrap(void);

    protected:
        std::string m_name;
        int     m_hit_points;
        int     m_energy_points;
        int     m_attack_damage;
};

#endif

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class   FragTrap : public ClapTrap
{
    public:
        // Constructor
        FragTrap(void);
        FragTrap(std::string name);

        // Copy Constructor
        FragTrap(const FragTrap& other);

        // Copy Assignment
        FragTrap& operator = (const FragTrap& other);

        // High Fiver
        void    HighFivesGuys(void);

        // Destructor
        ~FragTrap(void);
};

#endif

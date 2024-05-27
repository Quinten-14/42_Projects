#include "./main.h"

int main(void)
{
    std::string Fighter1 = "Quinten";
    std::string Fighter2 = "Bradley";
    ClapTrap    claptrap1(Fighter1);
    ClapTrap    claptrap2(Fighter2);

    std::cout << "\n<------- Moves ------->\n" << std::endl;
    claptrap1.attack(Fighter2);
    claptrap2.takeDamage(5);

    claptrap2.attack(Fighter1);
    claptrap1.takeDamage(15);

    claptrap1.attack(Fighter1);

    claptrap2.beRepaired(10);
    claptrap1.beRepaired(10);
    std::cout << "\n<------- Moves ------->\n" << std::endl;
}

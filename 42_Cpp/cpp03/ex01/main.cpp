#include "./main.h"

int main(void)
{
    std::string Fighter1 = "Quinten";
    std::string Fighter2 = "Bradley";
    ScavTrap    scavtrap1(Fighter1);
    ScavTrap    scavtrap2(Fighter2);

    std::cout << "\n<------- Moves ------->\n" << std::endl;
    scavtrap1.attack(Fighter2);
    scavtrap2.takeDamage(40);
    scavtrap2.attack(Fighter1);
    scavtrap1.takeDamage(20);
    scavtrap1.beRepaired(20);
    scavtrap1.guardGate();
    scavtrap1.attack(Fighter2);
    scavtrap2.takeDamage(200);
    scavtrap2.beRepaired(100);
    scavtrap2.guardGate();
    std::cout << "\n<------- Moves ------->\n" << std::endl;
}

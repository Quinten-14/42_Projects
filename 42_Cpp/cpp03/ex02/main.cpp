#include "./main.h"

int main(void)
{
    std::string Fighter1 = "Quinten";
    std::string Fighter2 = "Bradley";
    FragTrap    fragtrap1(Fighter1);
    FragTrap    fragtrap2(Fighter2);

    std::cout << "\n<------- Moves ------->\n" << std::endl;
    fragtrap1.attack(Fighter2);
    fragtrap2.takeDamage(30);
    fragtrap2.beRepaired(100);
    fragtrap1.HighFivesGuys();
    fragtrap2.beRepaired(20);
    std::cout << "\n<------- Moves ------->\n" << std::endl;
}

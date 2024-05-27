/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:24:59 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:01 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// Constructor
HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
    std::cout << "Created Human B" << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->m_weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (this->m_weapon)
        std::cout << this->m_name << " attacks with " << this->m_weapon->getType() << std::endl;
    else
        std::cout << this->m_name << " attacks with bare fists" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "Destroyed Human B" << std::endl;
}

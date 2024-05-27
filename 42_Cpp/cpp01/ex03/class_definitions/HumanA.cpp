/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:24:56 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:24:57 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// Constructor
HumanA::HumanA(std::string name, Weapon& weapon_type) : m_name(name), m_weapon(&weapon_type)
{
    std::cout << "Created Human A" << std::endl;
}

// Attack
void    HumanA::attack(void)
{
    std::cout << this->m_name << " attacks with " << this->m_weapon->getType() << std::endl;
}

// Destructor
HumanA::~HumanA(void)
{
    std::cout << "Destroyed Human A" << std::endl;
}

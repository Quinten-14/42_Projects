/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:04 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:05 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// Constructor
Weapon::Weapon(std::string type)
{
    this->m_type = type;
    std::cout << "Weapon Created" << std::endl;
}

// Type Setter
void    Weapon::setType(std::string new_type)
{
    this->m_type = new_type;
}

// Type Getter
const std::string&   Weapon::getType(void)
{
    return (this->m_type);
}

// Destructor
Weapon::~Weapon(void)
{
    std::cout << "Weapon Destroyed" << std::endl;
}

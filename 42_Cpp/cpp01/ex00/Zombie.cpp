/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:20:53 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:20:58 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./zombie.h"

// Constructor
Zombie::Zombie(std::string name)
{
    this->m_name = name;
}

// Announcer
void    Zombie::announcer(void)
{
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor
Zombie::~Zombie(void)
{
    std::cout << this->m_name << " Died of hunger.." << std::endl;
}

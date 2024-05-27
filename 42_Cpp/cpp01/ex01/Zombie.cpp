/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:21:31 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:21:33 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->m_name = name;
    std::cout << "Zombie " << this->m_name << " Created" << std::endl;
}

Zombie::Zombie(void)
{
    this->m_name = "(NULL)";
    std::cout << "Zombie " << this->m_name << " Created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->m_name << " Died of hunger.." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->m_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    std::cout << "Changed " << this->m_name;
    this->m_name = name;
    std::cout << " To " << this->m_name << std::endl;
}

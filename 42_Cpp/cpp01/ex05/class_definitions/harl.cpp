/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:54 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:56 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// Constructor
Harl::Harl(void)
{
    std::cout << "Created Harl" << std::endl;
}

void    Harl::m_debug(void)
{
    std::cout << "Harl Debug Level" << std::endl;
}

void    Harl::m_info(void)
{
    std::cout << "Harl Info Level" << std::endl;
}

void    Harl::m_warning(void)
{
    std::cout << "Harl Warning Level" << std::endl;
}

void    Harl::m_error(void)
{
    std::cout << "Harl Error Level" << std::endl;
}

// Complainer
void    Harl::complain(std::string level)
{
    void    (Harl::*ptr[4])(void) = {&Harl::m_debug, &Harl::m_info, &Harl::m_warning, &Harl::m_error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
        if (level == levels[i])
            return ((this->*ptr[i])());
}

// Destructor
Harl::~Harl(void)
{
    std::cout << "Destroyed Harl" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:20:31 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:20:32 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./zombie.h"

// Create a new zombie
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}

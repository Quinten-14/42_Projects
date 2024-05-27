/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:21:40 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:21:41 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *horde = new Zombie[N];
    std::cout << "\nChanging the name of all the zombies in a horde" << std::endl;
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}

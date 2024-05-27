/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:21:25 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:21:28 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void)
{
    std::cout << "Zombies get created as NULL" << std::endl;
    Zombie *horde = zombieHorde(10, "Zom");
    std::cout << "\nThe whole horde prints the announcement message" << std::endl;
    for (int i = 0; i < 10; i++)
        horde[i].announce();
    std::cout << "\nDelete the whole horde (fix memory leaks)" << std::endl;
    delete[] horde;
}

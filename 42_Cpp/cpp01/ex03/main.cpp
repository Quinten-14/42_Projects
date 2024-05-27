/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:08 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:09 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int main(void)
{
    HumanB  Jim("Jim");
    Jim.attack();

    // Subject Test
    /*
    {
        Weapon  club = Weapon("crude spiked club");

        HumanA  bob("Bob", club);
        bob.attack();
        club.setType("Some other type of club");
        bob.attack();
    }
    {
        Weapon  club = Weapon("crude spiked club");

        HumanB  Jim("Jim");
        Jim.setWeapon(club);
        Jim.attack();
        club.setType("Some other type of club");
        Jim.attack();
    }
    */

    return (0);
}

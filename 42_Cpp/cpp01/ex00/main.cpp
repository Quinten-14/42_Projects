/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:20:04 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:20:09 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./zombie.h"

int main(void)
{
    Zombie *zombie = newZombie("Jens");
    zombie->announcer();
    randomChump("Max");
    delete zombie;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:20:42 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:20:49 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./zombie.h"

void    randomChump(std::string name)
{
    Zombie  zombie = Zombie(name);
    zombie.announcer();
}

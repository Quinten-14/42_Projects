/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:59 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:26:00 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int main(void)
{
    Harl    h;

    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:46:50 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/13 17:46:52 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cout
#include <iostream>

// To upper string conversion
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);

    for (int i = 1; av[i]; i++)
        for (int j = 0; av[i][j]; j++)
            std::cout << static_cast<char>(std::toupper(av[i][j]));
    std::cout << '\n';
}

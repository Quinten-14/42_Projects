/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:24:28 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:24:29 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string string;
    std::string *stringPTR;

    string = "HI THIS IS BRAIN";
    stringPTR = &string;
    std::string &stringREF = string;
    std::cout << "string address: " << &string << std::endl;
    std::cout << "stringPTR address: " << stringPTR << std::endl;
    std::cout << "stringREF address: " << &stringREF << std::endl;
    std::cout << "stringPTR string: " << *stringPTR << std::endl;
    std::cout << "stringREF string: " << stringREF << std::endl;
}

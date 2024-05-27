/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_main.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:04:07 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/15 13:04:09 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./phonebook_main.hpp"

int main(void)
{
    std::cout << "Enter the command that you want to execute: 'ADD', 'SEARCH' or 'EXIT'\n";

    PhoneBook   phonebook;

    std::string input = "";
    while (input.compare("EXIT"))
    {
        if (std::cin.eof())
        {
            std::cout << "\nExiting\n";
            std::exit(EXIT_SUCCESS);
        }

        if (input.compare("ADD") == 0)
        {
            Contact contact;
            contact.new_contact();
            phonebook.add_contact(contact);
            std::cout << "\nWhat would you like to do next? (ADD, SEARCH or EXIT)\n";
        }
        else if (input.compare("SEARCH") == 0)
        {
            if (phonebook.any_contacts() == true)
            {
                phonebook.print_contacts();
                phonebook.search();
            }
            else
                std::cout << "You don't have any contacts\n";
            std::cout << "What would you like to do next? (ADD, SEARCH or EXIT)\n";
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return (0);
}

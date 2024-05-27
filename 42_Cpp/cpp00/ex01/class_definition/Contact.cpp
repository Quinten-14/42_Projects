/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:04:14 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/15 13:04:16 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../phonebook_main.hpp"

Contact::Contact(void)
{
    for (int i = 5; i < 5; i++)
        contact_info[i] = "";
}

void    Contact::new_contact(void)
{
    const std::string params[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for (int i = 0; i < 5; i++)
    {
        std::cin.clear();
        std::cout << "Please enter the " << params[i] << ": ";
        std::getline(std::cin, contact_info[i]);

        if (std::cin.eof())
        {
            std::cout << "\nExiting\n";
            std::exit(EXIT_SUCCESS);
        }

        if (contact_info[i].empty())
        {
            i--;
            std::cerr << "\nInvalid input: fields may not be empty.\n\n";
        }
    }
}

std::string Contact::printLen(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool    Contact::exists(int index) const
{
    if (contact_info[0].empty() || contact_info[1].empty() || contact_info[2].empty())
        return (false);
    return (true);
}

void    Contact::view(int index) const
{
    if (contact_info[0].empty() || contact_info[1].empty() || contact_info[2].empty())
        return ;
    
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << printLen(contact_info[0]) << std::flush;
    std::cout << "|" << std::setw(10) << printLen(contact_info[1]) << std::flush;
    std::cout << "|" << std::setw(10) << printLen(contact_info[2]) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const
{
    if (contact_info[0].empty() || contact_info[1].empty() || contact_info[2].empty())
        return ((void)(std::cout << "This contact is empty" << std::endl));

    std::cout << std::endl;
    std::cout << "-- Info From #" << index << " --" << std::endl;
    std::cout << "First Name:\t" << contact_info[0] << std::endl;
    std::cout << "Last Name:\t" << contact_info[1] << std::endl;
    std::cout << "Nickname:\t" << contact_info[2] << std::endl;
    std::cout << "Phone Number:\t" << contact_info[3] << std::endl;
    std::cout << "Darkest Secret:\t" << contact_info[4] << std::endl;
    std::cout << std::endl;
}

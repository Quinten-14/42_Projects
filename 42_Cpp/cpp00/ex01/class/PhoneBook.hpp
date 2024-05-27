/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:04:30 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/15 13:04:32 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../phonebook_main.hpp"

// const keyword is used when the functions don't change anything in the
// object. So for example when the functions only print stuff
class   PhoneBook
{
    public:
        PhoneBook(void);

        void    add_contact(const Contact contact);

        void    print_contacts(void) const;
        
        void    search(void) const;

        bool    any_contacts(void) const;
    private:
        Contact contacts[8];
        int current_index;
};

#endif

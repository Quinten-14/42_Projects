/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:04:26 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/15 13:04:27 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "../phonebook_main.hpp"

class   Contact
{
    public:
        Contact(void);

        void    new_contact(void);
        void    view(int index) const;
        void    display(int index) const;
        bool    exists(int index) const;

    private:
        std::string contact_info[5];
        std::string printLen(std::string str) const;
};

#endif

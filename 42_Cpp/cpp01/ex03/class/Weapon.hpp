/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:24:51 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:24:53 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

class   Weapon
{
    public:

        // Constructor
        Weapon(std::string type);

        // Set the type to something new
        void    setType(std::string new_type);

        // Get type function
        const std::string&  getType(void);

        // Destructor
        ~Weapon(void);

    private:
        std::string m_type;
};

#endif

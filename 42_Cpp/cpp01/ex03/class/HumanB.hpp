/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:24:48 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:24:49 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

class   HumanB
{
    public:
        // Constructor
        HumanB(std::string name);

        // Setter
        void    setWeapon(Weapon& weapon);

        // Attack
        void    attack(void);

        // Destructor
        ~HumanB(void);

    private:
        std::string m_name;
        Weapon* m_weapon;
};

#endif

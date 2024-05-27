/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:24:44 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:24:45 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

class   HumanA
{
    public:
        // Constructor
        HumanA(std::string name, Weapon& weapon_type);

        // Attack
        void    attack(void);
        
        // Destructor
        ~HumanA(void);

    private:
        std::string m_name;
        Weapon* m_weapon;
};

#endif

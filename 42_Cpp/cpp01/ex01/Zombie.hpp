/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:21:36 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:21:37 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class   Zombie
{
    public:

        // Default constructor
        Zombie(void);

        // String Constructor
        Zombie(std::string name);

        // Destructor
        ~Zombie(void);

        // Add names to the object
        void    setName(std::string name);

        // Couts Brainz message
        void    announce(void);

    private:
        std::string m_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:21:08 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:21:10 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "../zombie.h"

class   Zombie
{
    public:
        // constructor
        Zombie(std::string m_name);

        void    announcer(void);

        // destructor
        ~Zombie(void);

    private:
        std::string m_name;
};

#endif

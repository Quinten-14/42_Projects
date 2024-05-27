/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:50 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:51 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

class   Harl
{
    public:

        // Constructor
        Harl(void);

        // Complain Function
        void    complain(std::string level);

        // Destructor
        ~Harl(void);

    private:
        // Levels
        void    m_debug(void);
        void    m_info(void);
        void    m_warning(void);
        void    m_error(void);
};

#endif

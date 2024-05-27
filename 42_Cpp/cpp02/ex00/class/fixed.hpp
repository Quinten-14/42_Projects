/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:50:17 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/27 16:50:18 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class   Fixed
{
    public:
        // Constructor
        Fixed(void);

        // Copy Constructor
        Fixed(const Fixed& other);

        // Copy Assignment overload
        Fixed& operator = (const Fixed& other);

        // Getter
        int getRawBits(void) const;

        // Setter
        void setRawBits(int const raw);

        // Destructor
        ~Fixed(void);

    private:
        int m_fixed_point;
        static const int    m_fractional_bits = 8;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:50:51 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/27 16:50:52 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class   Fixed
{
    public:
        // Constructors
        Fixed(void);
        Fixed(const int);
        Fixed(const float);

        // Copy constructor
        Fixed(const Fixed& other);

        // Copy Assignment overload
        Fixed& operator = (const Fixed& other);

        // Getter
        int getRawBits(void) const;

        // Setter
        void setRawBits(int const raw);

        // Convert to float
        float   toFloat(void) const;

        // Convert to int
        int toInt(void) const;

        // Destructor
        ~Fixed(void);

    private:
        int m_fixed_point;
        static const int m_fractional_bits = 8;
};

#endif

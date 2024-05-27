/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:51:24 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:25 by qraymaek         ###   ########.fr       */
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

        // > operator overloader
        bool    operator > (const Fixed& other) const;

        // < operator overloader
        bool    operator < (const Fixed& other) const;
        
        // >= operator overloader
        bool    operator >= (const Fixed& other) const;
        
        // <= operator overloader
        bool    operator <= (const Fixed& other) const;
        
        // == operator overloader
        bool    operator == (const Fixed& other) const;
        
        // != operator overloader
        bool    operator != (const Fixed& other) const;

        // + operator overloader
        Fixed    operator + (const Fixed& other) const;
        
        // - operator overloader
        Fixed    operator - (const Fixed& other) const;
        
        // * operator overloader
        Fixed    operator * (const Fixed& other) const;
        
        // / operator overloader
        Fixed    operator / (const Fixed& other) const;

        // ++ operator overloader (pre)
        Fixed&  operator ++ (void);
        
        // -- operator overloader (pre)
        Fixed&  operator -- (void);

        // ++ operator overloader (post)
        Fixed   operator ++ (int);
        
        // -- operator overloader (post)
        Fixed   operator -- (int);

        // smallest of two
        static Fixed& min(Fixed& value_one, Fixed& value_two);
        
        // smallest of two
        static const Fixed& min(const Fixed& value_one, const Fixed& value_two);

        // greatest of two
        static Fixed& max(Fixed& value_one, Fixed& value_two);
        
        // greatest of two
        static const Fixed& max(const Fixed& value_one, const Fixed& value_two);

        // Destructor
        ~Fixed(void);

    private:
        int m_fixed_point;
        static const int m_fractional_bits = 8;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:51:12 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:20 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// Constructor
Fixed::Fixed(void)
{
    std::cout << "Called Default Constructor" << std::endl;
    this->m_fixed_point = 0;
}

// Constructor (int)
Fixed::Fixed(const int value)
{
    std::cout << "Called Integer Constructor" << std::endl;
    this->m_fixed_point = value << this->m_fractional_bits;
}

// Constructor (float)
Fixed::Fixed(const float value)
{
    std::cout << "Called Float Constructor" << std::endl;
    this->m_fixed_point = roundf(value * (1 << this->m_fractional_bits));
}

// Copy Constructor
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Called Copy Constructor" << std::endl;
    *this = other;
}

// Copy Assignment
Fixed&  Fixed::operator = (const Fixed& other)
{
    std::cout << "Called Copy Assignment operator" << std::endl;
    if (this != &other)
        this->m_fixed_point = other.getRawBits();
    return (*this);
}

int     Fixed::getRawBits(void) const
{
    std::cout << "Get Raw Bits Called" << std::endl;
    return (this->m_fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "Set Raw Bits Called" << std::endl;
    this->m_fixed_point = raw;
}

int     Fixed::toInt(void) const
{
    std::cout << "To Integer Called" << std::endl;
    return (this->m_fixed_point >> this->m_fractional_bits);
}

float   Fixed::toFloat(void) const
{
    std::cout << "To Float Called" << std::endl;
    return (static_cast<float>(this->m_fixed_point) / (1 << this->m_fractional_bits));
}

bool    Fixed::operator > (const Fixed& other) const
{
    return  (this->m_fixed_point > other.m_fixed_point);
}

bool    Fixed::operator < (const Fixed& other) const
{
    return (this->m_fixed_point < other.m_fixed_point);
}

bool    Fixed::operator >= (const Fixed& other) const
{
    return (this->m_fixed_point >= other.m_fixed_point);
}

bool    Fixed::operator <= (const Fixed& other) const
{
    return (this->m_fixed_point <= other.m_fixed_point);
}

bool    Fixed::operator == (const Fixed& other) const
{
    return (this->m_fixed_point == other.m_fixed_point);
}

bool    Fixed::operator != (const Fixed& other) const
{
    return (this->m_fixed_point != other.m_fixed_point);
}

Fixed   Fixed::operator + (const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed   Fixed::operator - (const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed   Fixed::operator * (const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed   Fixed::operator / (const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed&  Fixed::operator ++ (void)
{
    ++(this->m_fixed_point);
    return (*(this));
}

Fixed&  Fixed::operator -- (void)
{
    --(this->m_fixed_point);
    return (*(this));
}

Fixed   Fixed::operator ++ (int)
{
    Fixed result(*this);
    ++(this->m_fixed_point);
    return (result);
}

Fixed   Fixed::operator -- (int)
{
    Fixed result(*this);
    --(this->m_fixed_point);
    return (result);
}

Fixed&  Fixed::min(Fixed& value_one, Fixed& value_two)
{
    return (value_one < value_two ? value_one : value_two);
}

const Fixed&  Fixed::min(const Fixed& value_one, const Fixed& value_two)
{
    return (value_one < value_two ? value_one : value_two);
}

Fixed&  Fixed::max(Fixed& value_one, Fixed& value_two)
{
    return (value_one > value_two ? value_one : value_two);
}

const Fixed&  Fixed::max(const Fixed& value_one, const Fixed& value_two)
{
    return (value_one > value_two ? value_one : value_two);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor Called" << std::endl;
}

std::ostream& operator << (std::ostream& output, const Fixed& fixed_obj)
{
    output << fixed_obj.toFloat();
    return (output);
}

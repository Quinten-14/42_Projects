/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:50:02 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/27 16:50:08 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int main(void)
{
    std::cout << "Subject tests\n" << std::endl;

    Fixed   a;
    Fixed   b(a);
    Fixed   c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    std::cout << "\nOwn tests\n" << std::endl;

    Fixed   d;

    std::cout << d.getRawBits() << std::endl;

    d.setRawBits(100);

    std::cout << d.getRawBits() << std::endl;

    Fixed   e(d);

    std::cout << e.getRawBits() << std::endl;

    Fixed   f;

    f = d;

    std::cout << f.getRawBits() << std::endl;

    std::cout << "\nDestructors\n" << std::endl;

    return (0);
}

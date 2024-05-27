/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:51:07 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:08 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <iostream>
#include <cmath>

#include "./class/Fixed.hpp"

// overload the output for fixed class objects
std::ostream& operator << (std::ostream& output, const Fixed& fixed_obj);

#endif

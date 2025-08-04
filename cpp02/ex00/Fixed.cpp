/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:55:15 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/18 02:25:30 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
    nb = 0;
    std::cout << "Default constructor called" << std::endl; 
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl; 
    nb = copy.nb;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        nb = other.nb;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return nb;
}

void   Fixed::setRawBits(int const raw)
{
    nb = raw;
}


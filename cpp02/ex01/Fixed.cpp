/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:55:15 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/22 09:31:10 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include <cmath>

Fixed::Fixed() 
{
    nb = 0;
    std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl; 
    nb = number << rawBit;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;  
    nb = (number * (1 << rawBit));
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

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

float Fixed::toFloat(void) const
{
    return (float)nb / (1 << rawBit);
}

int Fixed::toInt( void ) const
{
    return nb >> rawBit;
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:51:23 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/22 10:52:41 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : nb(0) {}

Fixed::Fixed(const int number)
{
    nb = number << rawBit;
}

Fixed::Fixed(const float number)
{
    nb = roundf(number * (1 << rawBit));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy)
{
    nb = copy.nb;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        nb = other.nb;
    return *this;
}

Fixed Fixed::operator+(const Fixed &other)const
{
    Fixed res;
    res.nb = nb + other.nb;
    return res;
}

Fixed Fixed::operator-(const Fixed &other)const
{
    Fixed res;
    res.nb = nb - other.nb;
    return res;
}

Fixed Fixed::operator*(const Fixed &other)const
{
    Fixed res;
    res.nb = (nb * other.nb) >> rawBit;
    return res;
}

Fixed Fixed::operator/(const Fixed &other)const
{
    Fixed res;
        res.nb = (nb << rawBit) / other.nb;
    return res;
}

Fixed& Fixed::operator++(void)  
{
    nb++;
    return *this;
}

Fixed& Fixed::operator--(void)
{
    nb--;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed tmp(*this);
    nb++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    nb--;
    return tmp;
}

bool Fixed::operator<(const Fixed &other)
{
    return nb < other.nb;
}

bool Fixed::operator>(const Fixed &other)
{
    return nb > other.nb;
}

bool Fixed::operator>=(const Fixed &other)
{
    return nb >= other.nb;
}

bool Fixed::operator<=(const Fixed &other)
{
    return nb <= other.nb;
}

bool Fixed::operator==(const Fixed &other)
{
    return nb == other.nb;
}

bool Fixed::operator!=(const Fixed &other)
{
    return nb != other.nb;
}

float Fixed::toFloat(void) const
{
    return (float)nb / (1 << rawBit);
}

int Fixed::toInt(void) const
{
    return nb >> rawBit;
}

int Fixed::getRawBits(void) const
{
    return nb;
}

void Fixed::setRawBits(int const raw)
{
    nb = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    return (f1.nb < f2.nb) ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    return (f1.nb < f2.nb) ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    return (f1.nb > f2.nb) ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    return (f1.nb > f2.nb) ? f1 : f2;
}

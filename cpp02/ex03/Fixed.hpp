/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:29:29 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/21 15:55:23 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int              nb;
    const static int rawBit = 8;

public:
    Fixed();
   ~Fixed(); 
    
    Fixed  (const Fixed &copy);
    Fixed &operator=(const Fixed &other);
    
    
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed   &operator--(void);
    Fixed   &operator++(void);

    Fixed operator--(int);
    Fixed operator++(int);


    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    
    bool operator<=(const Fixed &other);
    bool operator>=(const Fixed &other);

    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);

    static Fixed &min(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);


    Fixed(const int number);
    Fixed(const float number);
    float toFloat(void) const;

    int toInt( void ) const;

    int    getRawBits(void) const;
    void   setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:29:29 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/18 00:02:25 by edubois-         ###   ########.fr       */
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

    int    getRawBits(void) const;
    void   setRawBits(int const raw);
};

#endif
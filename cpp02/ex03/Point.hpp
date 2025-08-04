/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:31:08 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/22 16:23:40 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &copy);
        Point &operator=(const Point &other);
       ~Point();    
    
       const Fixed &getY(void);
       const Fixed &getX(void);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:38:12 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/22 16:33:38 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() 
{
    Fixed x;
    Fixed y;
}

Point::Point(const float xv, const float yv) : x(xv), y(yv) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point& Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Point::~Point()
{
}
const Fixed &Point::getY(void)
{
    return y;
}

const Fixed &Point::getX(void)
{
    return x;
}

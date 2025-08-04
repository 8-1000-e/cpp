/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:57 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/23 09:15:34 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//produit vectoriel 2D 
// return Positif : les points sont orientes dans un sens
// 
// Negatif : dans l autre sens
// 
// Zero : aligne

float sign(Point p1, Point p2, Point p3) {
    return (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) -
           (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat());
}



//prend le produit vectoriel du point par rapport a chaque cote du triangle
//verifie si il ets du meme cote pour tout les points, si oui, il ets dans le triangle 
bool bsp(Point const a, Point const b, Point const c, Point const p) {
    float d1 = sign(p, a, b);
    float d2 = sign(p, b, c);
    float d3 = sign(p, c, a);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
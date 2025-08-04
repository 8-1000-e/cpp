/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:40:31 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 10:29:42 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t) {type = t;};

Weapon::Weapon() {};

Weapon::~Weapon() {};

const std::string &Weapon::getType() const
{
    return type;
}

void    Weapon::setType(std::string newType)
{
    type = newType;
}
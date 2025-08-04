/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:01:29 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 10:29:58 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;
    
public:
    Weapon(std::string);
    Weapon();
    ~Weapon();
    
    const std::string &getType() const;
    void         setType(std::string newType);

};

#endif
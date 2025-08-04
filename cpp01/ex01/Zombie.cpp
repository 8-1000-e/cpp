/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:03:52 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/04 14:36:09 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string n)
{
    name = n;
}

Zombie::Zombie()
{
    name = "no-name";
}

void Zombie::setName(std::string n)
{
    name = n;
}

Zombie::~Zombie(void)
{
    std::cout << name << " is destroyed." << std::endl;
}

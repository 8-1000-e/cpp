/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:53:46 by edubois-          #+#    #+#             */
/*   Updated: 2025/05/05 15:53:53 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt1("Diamond1");
    
    std::cout << "\n===== DiamondTrap 1 =====" << std::endl;
    std::cout << "Name = " << dt1.getName() << std::endl;
    std::cout << "ClapTrap Name = " << dt1.getClapTrapName() << std::endl;
    std::cout << "HitPoints = " << dt1.getHitPoints() << std::endl;
    std::cout << "EnergyPoints = " << dt1.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage = " << dt1.getAttackDamage() << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "===== Testing attack() =====" << std::endl;
    dt1.attack("Enemy1");
    std::cout << "\n" << std::endl;

    std::cout << "===== Testing whoAmI() =====" << std::endl;
    dt1.whoAmI();
    std::cout << "\n" << std::endl;

    std::cout << "\n===== Testing copy constructor =====" << std::endl;
    DiamondTrap dt2(dt1); 
    std::cout << "DiamondTrap 2:" << std::endl;
    std::cout << "Name = " << dt2.getName() << std::endl;
    std::cout << "ClapTrap Name = " << dt2.getClapTrapName() << std::endl;
    std::cout << "\n" << std::endl;

    DiamondTrap dt3("Diamond3");
    dt3 = dt1;
    std::cout << "\n===== Testing copy assignment operator =====" << std::endl;
    std::cout << "DiamondTrap 3:" << std::endl;
    std::cout << "Name = " << dt3.getName() << std::endl;
    std::cout << "ClapTrap Name = " << dt3.getClapTrapName() << std::endl;
    std::cout << "\n" << std::endl;

    return 0;
}

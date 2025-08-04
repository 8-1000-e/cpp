/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:13:50 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/24 13:15:53 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1("Alice");           
    ScavTrap scav2("Bob");

    std::cout << std::endl;
    ScavTrap copyScav(scav1);           
    ScavTrap assignedScav;
    assignedScav = scav2;              

    std::cout << std::endl;
    scav1.attack("Bob");               
    scav2.attack("Alice");           

    std::cout << std::endl;
    scav1.guardGate();
    scav1.attack("Bob");           

    std::cout << std::endl;
    for (int i = 1; i <= 55; ++i)
    {
        std::cout << "Attempt " << i << ": ";
        scav2.attack("Target");
    }

    std::cout << std::endl;
    scav1.takeDamage(120);          
    scav1.attack("Bob");
    scav1.beRepaired(10);

    std::cout << std::endl;
    return 0;
}

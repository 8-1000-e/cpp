/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:07:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/05 14:58:08 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << std::endl;
    FragTrap frag1("Alpha");
    FragTrap frag2("Beta");           

    std::cout << std::endl;
    FragTrap copyFrag(frag1);
    FragTrap assignedFrag;
    assignedFrag = frag2;             

    std::cout << std::endl;
    frag1.attack("Target1");
    frag2.attack("Target2");
    frag1.takeDamage(30);
    frag1.beRepaired(20);

    std::cout << std::endl;
    frag1.highFivesGuys();           

    std::cout << std::endl;
    for (int i = 1; i <= 35; ++i)
    {
        std::cout << "Attack attempt " << i << ": " << std::endl;
        frag2.attack("Dummy");
    }

    std::cout << std::endl;
    frag1.takeDamage(200);
    frag1.attack("Nothing");
    frag1.beRepaired(10);

    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:47:56 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/24 10:47:57 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("Bob");
    ClapTrap alice("Alice");

    std::cout << std::endl;

    bob.attack("Alice");
    alice.attack("Bob");

    std::cout << std::endl;

    alice.takeDamage(5);
    alice.beRepaired(3);

    std::cout << std::endl;

    for (int i = 0; i < 12; ++i)
        bob.attack("Alice");

    std::cout << std::endl;

    alice.takeDamage(20);

    std::cout << std::endl;

    alice.attack("Bob");
    alice.beRepaired(5);
    alice.takeDamage(5);

    std::cout << std::endl;

    ClapTrap clone(bob);
    ClapTrap copy;
    copy = alice;

    std::cout << std::endl;

    return 0;
}

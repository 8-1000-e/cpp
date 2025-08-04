/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:02:15 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 12:05:33 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = Zombie::newZombie("Zombie1");
    zombie1->announce();
    delete zombie1;

    Zombie::randomChump("Zombie2");
    return 0;
}
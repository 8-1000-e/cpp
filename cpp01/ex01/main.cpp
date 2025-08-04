/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:09:56 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 11:51:35 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main()
{
    int N = 5;
    std::string name = "Zombie";
    
    Zombie *horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete[] horde;

    return 0;
}
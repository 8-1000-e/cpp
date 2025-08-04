/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:05:37 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 12:05:37 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name; 
        
    public:
        Zombie(std::string name);
        ~Zombie(); 
        
        void announce(void);
        static Zombie* newZombie(std::string name);
        static void randomChump(std::string name); 
};

#endif
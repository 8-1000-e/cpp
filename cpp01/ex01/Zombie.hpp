/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:05:37 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 11:51:24 by edubois-         ###   ########.fr       */
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
        Zombie();
        Zombie(std::string name);
        ~Zombie(); 
        
        void announce(void);
        void setName(std::string n);
};
    
    Zombie *zombieHorde( int N, std::string name );

    
#endif
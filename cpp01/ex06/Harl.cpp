/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:39:32 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 12:04:02 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;   
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    
    // void = les fonctions return void
    
    // (Harl::*funcs[]) = de la classe Harl(Harl::), des pointeurs (*) et un tableau ([])
    
    // (void) = les fonctions ne prennent pas d args
    
    void (Harl::*funcs[])(void) =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    

    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            index = i;
            break;
        }
    }

    switch (index)
    {
    case 0:
            std::cout  << levels[0] << std::endl;
           (this->*funcs[0])();
            std::cout << std::endl;
    case 1:
            std::cout  << levels[1] << std::endl;
            (this->*funcs[1])();
            std::cout << std::endl;
    case 2:
            std::cout  << levels[2] << std::endl;
            (this->*funcs[2])();
            std::cout << std::endl;
    case 3:
            std::cout  << levels[3] << std::endl;
            (this->*funcs[3])();
            break;
    default: 
            std::cout << "Level not recognized !" << std::endl;
    }
    
}

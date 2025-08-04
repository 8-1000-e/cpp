/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:04:26 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 15:13:25 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string t)
{
    std::cout << "WrongAnimal Constructor called" << std::endl; 
    Type = t;
}

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl; 
    Type = "WrongUnNamed";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;     
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;     
    Type = copy.Type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
        this->Type = other.Type;
    }
    return *this;
}

std::string WrongAnimal::getType() const
{
    return Type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Average WrongAnimal sound, maybe like ARGHJGS, im an animal but a wrong one! " << std::endl; 
}
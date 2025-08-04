/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:04:26 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 14:51:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string t)
{
    std::cout << "Animal Constructor called" << std::endl; 
    Type = t;
}

Animal::Animal()
{
    std::cout << "Animal Default Constructor called" << std::endl; 
    Type = "UnNamed";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;     
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal Copy constructor called" << std::endl;     
    Type = copy.Type;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        std::cout << "Animal Copy assignment operator called" << std::endl;
        this->Type = other.Type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return Type;
}

void    Animal::makeSound() const
{
    std::cout << "Average Animal sound, maybe like ARGHJGS ! " << std::endl; 
}
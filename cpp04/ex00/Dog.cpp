/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:15:40 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 14:49:53 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(std::string t) : Animal(t)
{
    std::cout << "Dog Constructor called" << std::endl; 
}

Dog::Dog() : Animal("UndefinedDogName")
{
    std::cout << "Dog Default Constructor called" << std::endl; 
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;     
}

Dog::Dog(const Dog &copy) : Animal(copy.getType()) 
{
    std::cout << "Dog Copy constructor called" << std::endl;     
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        std::cout << "Dog Copy assignment operator called" << std::endl;
        Animal::operator=(other);
    }
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Wouf Wouf !!" << std::endl;
}
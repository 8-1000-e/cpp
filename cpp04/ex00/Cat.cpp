/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:15:40 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 14:49:43 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string t) : Animal(t)
{
    std::cout << "Cat Constructor called" << std::endl; 
}

Cat::Cat() : Animal("UndefinedCatName")
{
    std::cout << "Cat Default Constructor called" << std::endl; 
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;     
}

Cat::Cat(const Cat &copy) : Animal(copy.getType()) 
{
    std::cout << "Cat Copy constructor called" << std::endl;     
}

Cat &Cat::operator=(const Cat &other) 
{
    if (this != &other)
    {
        std::cout << "Cat Copy assignment operator called" << std::endl;
        Animal::operator=(other);
    }
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Meow Meow !!" << std::endl;
}
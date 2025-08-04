/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:15:40 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 15:51:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string t) : Animal(t)
{
    brain = new Brain();
    std::cout << "Cat Constructor called" << std::endl; 
}

Cat::Cat() : Animal("UndefinedCatName")
{
    brain = new Brain();
    std::cout << "Cat Default Constructor called" << std::endl; 
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;     
    delete brain;
}

Cat::Cat(const Cat &copy) : Animal(copy.getType()) 
{
    brain = new Brain(*copy.brain);
    std::cout << "Cat Copy constructor called" << std::endl;     
}

Cat &Cat::operator=(const Cat &other) 
{
    if (this != &other)
    {
        std::cout << "Cat Copy assignment operator called" << std::endl;
        brain = other.brain;
        Animal::operator=(other);
    }
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Meow Meow !!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index)
{
    if (brain)
        return brain->getIdea(index);
    return "";
}
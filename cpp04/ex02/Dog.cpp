/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:15:40 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 15:52:40 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(std::string t) : Animal(t)
{
    this->brain = new Brain();
    std::cout << "Dog Constructor called" << std::endl; 
}

Dog::Dog() : Animal("UndefinedDogName")
{
    this->brain = new Brain();
    std::cout << "Dog Default Constructor called" << std::endl; 
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;     
    delete brain;
}

Dog::Dog(const Dog &copy) : Animal(copy.getType()) 
{
    brain = new Brain(*copy.brain);
    std::cout << "Dog Copy constructor called" << std::endl;     
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        std::cout << "Dog Copy assignment operator called" << std::endl;
        Animal::operator=(other);
        brain = other.brain;
    }
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Wouf Wouf !!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index)
{
    if (brain)
        return brain->getIdea(index);
    return "";
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:15:40 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 15:09:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(std::string t) : WrongAnimal(t)
{
    std::cout << "WrongCat Constructor called" << std::endl; 
}

WrongCat::WrongCat() : WrongAnimal("WrongUndefinedCatName")
{
    std::cout << "WrongCat Default Constructor called" << std::endl; 
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;     
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy.getType()) 
{
    std::cout << "WrongCat Copy constructor called" << std::endl;     
}

WrongCat &WrongCat::operator=(const WrongCat &other) 
{
    if (this != &other)
    {
        std::cout << "WrongCat Copy assignment operator called" << std::endl;
        WrongAnimal::operator=(other);
    }
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "Meow Meow, im a cat but a wrong one !" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:34:31 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/17 14:49:27 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default Constructor called" << std::endl; 
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called" << std::endl;     
}

Ice::Ice(const Ice &copy)
{
    std::cout << "Ice Copy constructor called" << std::endl;   
    *this = copy;  
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Ice Copy assignment operator called" << std::endl;
    }
    return *this;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}
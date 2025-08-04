/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:34:31 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/17 14:46:56 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default Constructor called" << std::endl; 
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called" << std::endl;     
}

Cure::Cure(const Cure &copy)
{
    std::cout << "Cure Copy constructor called" << std::endl;   
    *this = copy;  
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Cure Copy assignment operator called" << std::endl;
    }
    return *this;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}
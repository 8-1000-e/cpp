/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:05:20 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/17 15:43:26 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & t)
{
    std::cout << "AMateria Constructor called" << std::endl; 
    Type = t;
}

AMateria::AMateria()
{
    std::cout << "AMateria Default Constructor called" << std::endl; 
    Type = "UnNamed";
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;     
}

AMateria::AMateria(const AMateria &copy)
{
    std::cout << "AMateria Copy constructor called" << std::endl;     
    Type = copy.Type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        std::cout << "AMateria Copy assignment operator called" << std::endl;
        this->Type = other.Type;
    }
    return *this;
}

const std::string& AMateria::getType() const
{
    return Type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
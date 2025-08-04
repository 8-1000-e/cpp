/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:59:36 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/17 16:06:45 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default Constructor called" << std::endl; 
    for (int i = 0; i < 4; i++)
        stack[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called" << std::endl;     
    for (int i = 0; i < 4; i++)
    {
        if (stack[i])
            delete stack[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "MateriaSource Copy constructor called" << std::endl;   
    for (int i = 0; i < 4; i++)
    {
        if (copy.stack[i])
            stack[i] = copy.stack[i]->clone();
        else
            stack[i] = NULL;
    }
    *this = copy;  
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
       for (int i = 0; i < 4; i++)
        {
            if (stack[i])
            {
                delete stack[i];
                stack[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.stack[i])
                stack[i] = other.stack[i]->clone();
            else
                stack[i] = NULL;
        }
        std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *source)
{
    int i = 0;
    while (stack[i] && i < 4)
        i++;
    if (i > 3)
        std::cout << "All learning slot are full" << std::endl;
    else
    {
        std::cout << source->getType() << " is getting learned" << std::endl;
        stack[i] = source; 
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    if (type != "cure" && type != "ice")
        std::cout << "Unknow type " << type << ", can't be created" << std::endl;
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (stack[i] && stack[i]->getType() == type)
            {
                std::cout << "New Materia of type " << type << " has been created" << std::endl;
                return (stack[i]->clone());
            }
        }
    }
    return NULL;
}

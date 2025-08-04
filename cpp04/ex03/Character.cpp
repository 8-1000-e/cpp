/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:33:08 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/18 10:36:43 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name)
{
    std::cout << "Character Constructor called" << std::endl; 
    Name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    dropped = new AMateria*[1];
    dropped[0] = NULL;
}

Character::Character()
{
    std::cout << "Character Default Constructor called" << std::endl; 
    Name = "UnNamed";
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    dropped = new AMateria*[1];
    dropped[0] = NULL;
}

void Character::expandDropped(AMateria *n)
{
    int i = 0;
    while (dropped[i])
        i++;
    AMateria **tmpDropped = new AMateria*[i + 2];
    for (int j = 0; j < i; j++)
        tmpDropped[j] = dropped[j];
    tmpDropped[i] = n;
    tmpDropped[i + 1] = NULL;
    if (dropped)
        delete[] dropped;
    dropped = tmpDropped;
}


Character::~Character()
{
    std::cout << "Character Destructor called" << std::endl;     
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
        inventory[i] = NULL;
    }
    for (int i = 0; dropped[i]; i++)
    {
        delete dropped[i];
        dropped[i] = NULL;
    }
    if (dropped)
        delete[] dropped;
}

Character::Character(const Character &copy)
{
    std::cout << "Character Copy constructor called" << std::endl;     
    Name = copy.Name;
    for (int i = 0; i < 4; i++)
    {
        if (copy.inventory[i])
            inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    dropped = new AMateria*[1];
    dropped[0] = NULL;
    for (int i = 0; copy.dropped[i]; i++)
        expandDropped(copy.dropped[i]->clone());
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        std::cout << "Character Copy assignment operator called" << std::endl;
        this->Name = other.Name;
       for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        for (int i = 0; dropped[i]; i++)
        {
                delete dropped[i];
                dropped[i] = NULL;
        }
        dropped = NULL;
        for (int i = 0; other.dropped[i]; i++)
            expandDropped(other.dropped[i]->clone());
    }
    return *this;
}

const std::string& Character::getName() const
{
    return Name;
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Cannot equip a NULL Materia" << std::endl;
        return;
    }
    int i = 0;
    while (i < 4 && inventory[i])
        i++;
    if (i == 4)
        std::cout << "Can't equip anymore Materia on " << this->getName() << std::endl;
    else
    {
        inventory[i] = m;
        std::cout << "Materia of type " << m->getType() <<" equipped in slot " << i << " on " << this->getName() << std::endl;
    }
}

void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        std::cout << "Inventory only have 4 slots, select an index between 0 and 3" << std::endl;
    else
    {
        if (!inventory[idx])
        {
            std::cout << "Can't unequip " << this->getName() << "'s slot " << idx <<  " because its empty" << std::endl; 
            return ;
        }
        else
        {
            expandDropped(inventory[idx]);
            std::cout << "AMateria " <<inventory[idx]->getType() << " has been drop to the floor" << std::endl;
            inventory[idx] = NULL;
        }
    }    
}

void Character::use(int index, ICharacter &target)
{
    if (index < 0 || index > 3)
        std::cout << "Inventory only have 4 slots, select an index between 0 and 3" << std::endl;
    else if (!inventory[index])
        std::cout << "Item on index " << index << " is empty !" << std::endl;
    else
        inventory[index]->use(target);
}
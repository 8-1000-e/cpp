/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:01:14 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/24 13:20:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl; 
    Name = "UnNamed";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    isDead = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;     
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;     
    Name = copy.Name;
    HitPoints = copy.HitPoints;
    EnergyPoints = copy.EnergyPoints;
    AttackDamage = copy.AttackDamage;
    isDead = copy.isDead;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        std::cout << "Copy assignement constructor called" << std::endl;
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
        this->isDead = other.isDead;
    }
    return *this;
}

ClapTrap::ClapTrap(std::string newName)
{
    std::cout << "Constructor called" << std::endl;
    Name = newName;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    isDead = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!isDead)
    {
        if (EnergyPoints)
            HitPoints+=amount;
        else
            std::cout << "ClapTrap " << this->Name << " tries to repair himself but he is out of energy" << std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (!isDead)
    {
        HitPoints -= amount;
        std::cout << Name << " takes " << amount << " amount of damage, new Hitpoints = " << HitPoints << std::endl;
        if (HitPoints <= 0)
        {
           isDead = 1; 
           std::cout << Name << " took too much damage, " << Name << " is dead" << std::endl; 
        }
        
    }
    else
        std::cout << "ClapTrap " << Name << " is already dead, can't take anymore damage" << std::endl;
}


void ClapTrap::attack(const std::string &target)
{
    if (this->EnergyPoints > 0 && !this->isDead)
    {
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else if (this->EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " tries to attack " << target << " but is out of energy." << std::endl;
    }
    else if (this->isDead)
    {
        std::cout << "ClapTrap " << this->Name << " tries to attack " << target << " but " << Name << " is dead." << std::endl;
    }
}



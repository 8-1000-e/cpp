/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:14:08 by edubois-          #+#    #+#             */
/*   Updated: 2025/05/05 15:46:47 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
    ClapTrap("UnNamed_clap_name"), 
    FragTrap(),
    ScavTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    Name = "UnNamed";
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"), 
    FragTrap(),
    ScavTrap()
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    Name = name;
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :
    ClapTrap(copy),
    FragTrap(copy), 
    ScavTrap(copy)  
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->Name = copy.Name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        std::cout << "Copy assignement constructor called" << std::endl;
        ClapTrap::operator=(other);
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;    
    }
    return *this;
}

void DiamondTrap::attack(const std::string target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "Name = " << Name << " ClapTrap Name = " << ClapTrap::Name << std::endl;
}

std::string DiamondTrap::getName() const
{
    return Name;
}

std::string DiamondTrap::getClapTrapName() const
{
    return ClapTrap::Name;
}

int DiamondTrap::getHitPoints() const
{
    return FragTrap::HitPoints;
}

int DiamondTrap::getEnergyPoints() const
{
    return ScavTrap::EnergyPoints;
}

int DiamondTrap::getAttackDamage() const
{
    return FragTrap::AttackDamage;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:08:14 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/24 13:59:40 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    GateKeep = 0;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    GateKeep = 0;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->Name = copy.Name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
    this->GateKeep = copy.GateKeep;
    this->isDead = copy.isDead;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        std::cout << "ScavTrap Copy assignement constructor called" << std::endl;
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
        this->isDead = other.isDead;
        this->GateKeep = other.GateKeep;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is in gatekeeper mode and won't be able to take damage or attack"<< std::endl;
    GateKeep = 1;
}

void ScavTrap::attack(const std::string target)
{
    if (this->EnergyPoints > 0 && !this->isDead && !GateKeep)
    {
        this->EnergyPoints--;
        std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!       New Energy Point = " << EnergyPoints << std::endl;
    }
    else if (this->EnergyPoints <= 0 && !GateKeep)
        std::cout << "ScavTrap " << this->Name << " tries to attack " << target << " but is out of energy." << std::endl;
    else if (this->isDead)
        std::cout << "ScavTrap " << this->Name << " tries to attack " << target << " but " << Name << " is dead." << std::endl;
    else if (this->GateKeep)
        std::cout << "ScavTrap " << this->Name << " tries to attack " << target << " but " << Name << " is in GateKeep mode" << std::endl;

        
}


    



    
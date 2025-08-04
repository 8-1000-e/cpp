/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:39:25 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/18 10:38:18 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    std::cout << std::endl;
    
    src->learnMateria(new Ice());
    std::cout << std::endl;
    
    src->learnMateria(new Cure());
    std::cout << std::endl;

    ICharacter* me = new Character("Arthur");
    std::cout << std::endl;

    AMateria* tmp;
    std::cout << std::endl;

    tmp = src->createMateria("ice");
    std::cout << std::endl;
    
    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    std::cout << std::endl;

    me->equip(tmp);
    std::cout << std::endl;

    
    std::cout << std::endl;
    tmp = src->createMateria("fire");
    std::cout << std::endl;
    
    ICharacter* bob = new Character("bob");
    std::cout << std::endl;
    
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;
    
    me->use(3, *bob);
    std::cout << std::endl;
    
    me->unequip(0);
    std::cout << std::endl;
    
    me->use(0, *bob);
    std::cout << std::endl;
    
    tmp = src->createMateria("ice");
    std::cout << std::endl;
    me->equip(tmp);
    std::cout << std::endl;
    
    Character clone_me(*(Character*)me);
    std::cout << std::endl;
    
    clone_me.use(0, *bob);
    clone_me.use(1, *bob);
    std::cout << std::endl;
    
    std::cout << std::endl;
    me->unequip(3);
    std::cout << std::endl;


    for (int i = 0; i < 10; i++)
    {
        Ice* tmp = new Ice();
        me->equip(tmp);
        me->unequip(2);
    }
    

    std::cout << std::endl;
    delete bob;
    delete me;
    delete src;

    return 0;
}

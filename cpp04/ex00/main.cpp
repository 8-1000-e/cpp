/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:07:54 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 15:14:18 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Test correct polymorphisme avec Animal ===" << std::endl << std::endl;
    const Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int i = 0; i < 3; ++i)
    {
        
        std::cout << std::endl << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }
    for (int i = 0; i < 3; ++i)
        delete animals[i];

    std::cout << std::endl << "=== Test faux polymorphisme avec WrongAnimal ===" << std::endl << std::endl;
    WrongAnimal* wrongAnimals[2];
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();
    std::cout << std::endl;

    for (int i = 0; i < 2; ++i)
    {
        std::cout << std::endl;
        std::cout << wrongAnimals[i]->getType() << " says: ";
        wrongAnimals[i]->makeSound();
    }
    std::cout << std::endl;

    for (int i = 0; i < 2; ++i)
        delete wrongAnimals[i];

    return 0;
}


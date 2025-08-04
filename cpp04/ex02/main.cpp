/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:07:54 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/18 10:44:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // AAnimal a;

    Animal* dog = new Dog();
    Animal* cat = new Cat();

    
    std::cout << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;


    delete dog;
    delete cat;

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:07:54 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 16:04:08 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N 4 // doit etre pair

int main()
{
    std::cout << "=== Création du tableau d'Animal ===" << std::endl << std::endl;
    Animal* animals[N];

    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    std::cout << std::endl << "=== Suppression du tableau d'Animal ===" << std::endl << std::endl;
    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << std::endl << "=== Test de copie profonde ===" << std::endl << std::endl;

    Dog original;

    std::cout << std::endl << "On modifie une idée dans le Brain de original" << std::endl;
    original.setIdea(0, "Chasser le facteur");

    std::cout << std::endl << "Création d'une copie du Dog original" << std::endl;
    Dog copie = original;

    std::cout << std::endl;
    std::cout << "L’idée 0 du Dog original: " << original.getIdea(0) << std::endl;
    std::cout << "L’idée 0 du Dog copie   : " << copie.getIdea(0) << std::endl;

    std::cout << std::endl << "On modifie l’idée 0 du Dog copie" << std::endl;
    copie.setIdea(0, "Manger des croquettes");

    std::cout << std::endl;
    std::cout << "L’idée 0 du Dog original: " << original.getIdea(0) << std::endl;
    std::cout << "L’idée 0 du Dog copie   : " << copie.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "=== Fin du programme ===" << std::endl << std::endl;

    return 0;
}

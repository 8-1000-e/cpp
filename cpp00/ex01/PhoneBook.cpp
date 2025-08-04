/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:05:24 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/02 16:37:17 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) , count(0){}

void    PhoneBook::addContact()
{
    int error = 0;

    if (count < 8)
    {
        error = 0;
        Contact[count].setContact(error);
        if (!error)
            count++; 
    }
    else
    {
        error = 0;
        Contact[index].setContact(error); 
        if (!error)
            index = (index + 1) % 8;
    }
}

void    PhoneBook::displayContacts() const
{
    std::cout << "┌───────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│ id    │   prenom │    nom   │  surnom  │" << std::endl;
    std::cout << "└───────┴──────────┴──────────┴──────────┘" << std::endl;
    
    for (int i = 0; i < 8; i++)
    {
        std::cout << "├───────┼──────────┼──────────┼──────────┤ " << std::endl;
        Contact[i].displayShort(i);
    }
    std::cout << "└───────┴──────────┴──────────┴──────────┘" << std::endl;
}

bool valid_index(std::string index)
{
    if (index.length() == 1)
    {
        if ((index[0]) >= '0' && (index[0]) <= '9')
            return true;
    }
    return false;
}

void    PhoneBook::searchContact() const
{
    std::string i;
    
    displayContacts();
    std::cout << "Entrez un index " << std::endl;
    std::getline(std::cin,  i);
    if (valid_index(i))
        Contact[i[0] - '0'].displayFull();
    else
        std::cout << "Erreur: index non valide" << std::endl;
}
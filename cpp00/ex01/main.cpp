/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:21:41 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:42 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Entrez une commande (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break ;
        if (command == "ADD") 
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Au revoir !" << std::endl;
            break;
        }
        else
            std::cout << "Commande invalide." << std::endl;
    }
    return 0;
}
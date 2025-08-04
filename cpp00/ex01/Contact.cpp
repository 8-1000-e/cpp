/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:27:34 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/02 16:11:37 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

bool isValidPhoneNumber(const std::string &phoneNumber) {
    if (phoneNumber.length() != 10)
        return false;
    
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        if (!isdigit(phoneNumber[i]))
            return false;
    }

    return true;
}

void Contact::reset()
{
    firstName.clear();
    lastName.clear();
    nickname.clear();
    phoneNumber.clear();
    darkestSecret.clear();
}

bool isValidArg(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (std::isspace(str[i]) && str[i] != ' ')
        {
            std::cout << "Erreur: mauvais formatage d'argument" << std::endl;
            return false;
        }
    return true;
}

void    Contact::setContact(int &error)
{
    std::cout << "Entrez le prenom" << std::endl;
    std::getline(std::cin, firstName);
    if (firstName.empty() || !isValidArg(firstName))
    {
        reset();
        error = 1;
        std::cout << "Erreur: Veuillez entrer un prenom valide" << std::endl;
        return ;
    }
    
    std::cout << "Entrez le nom de famillle" << std::endl;
    std::getline(std::cin, lastName);
    if (lastName.empty() || !isValidArg(lastName))
    {
        reset();
        error = 1;
        std::cout << "Erreur: Veuillez entrer un nom valide" << std::endl;
        return ;
    }
    
    std::cout << "Entrez le surnom" << std::endl;
    std::getline(std::cin, nickname);
    if (nickname.empty() || !isValidArg(nickname))
    {
        reset();
        error = 1;
        std::cout << "Erreur: Veuillez entrer un surnom valide" << std::endl;
        return ;
    }
    
    std::cout << "Entrez le numero de telephone" << std::endl;
    std::getline(std::cin, phoneNumber);
    if (!isValidPhoneNumber(phoneNumber))
    {
        reset();
        error = 1;
        std::cout << "Erreur: Veuillez entrer un numero de telephone valide" << std::endl;
        return ;
    }
    
    std::cout << "Entrez votre secret le plus sombre" << std::endl;
    std::getline(std::cin, darkestSecret);
    if (darkestSecret.empty() || !isValidArg(darkestSecret))
    {
        reset();
        error = 1;
        std::cout << "Erreur: Veuillez entrer un secret valide" << std::endl;
        return ;
    }
}

void    Contact::displayShort(int index) const
{    
    std::cout << "│" << std::setw(7) << std::right << index << "│"
    << std::setw(10) << std::right << (firstName.length() <= 10 ? firstName : firstName.substr(0, 9) + ".") << "│" 
    << std::setw(10) << std::right << (lastName.length() <= 10 ? lastName : lastName.substr(0, 9) + ".") << "│" 
    << std::setw(10) << std::right << (nickname.length() <= 10 ? nickname : nickname.substr(0, 9) + ".") << "│" 
    << std::endl;
}

void    Contact::displayFull() const
{
    std::cout << std::endl << "Prenom: " << firstName
        << std::endl << "Nom: " << lastName
        << std::endl << "Surnom: " << nickname
        << std::endl << "Numero de telephone: " << phoneNumber
        << std::endl << "Secret: " << darkestSecret << std::endl;
}

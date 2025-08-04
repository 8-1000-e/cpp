/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:28:49 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 17:57:50 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string str[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i = -1;
    
    for (int j = 0; j < 3; j++)
    {
        if (str[j] == name)
            i = j;
    }
    
    switch (i)
    {
        case 0:
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);
        case 1:
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm(target);
        default:
            std::cerr << "Error: Form name \"" << name << "\" does not exist." << std::endl;
            throw NoFormFoundException();
    }
}

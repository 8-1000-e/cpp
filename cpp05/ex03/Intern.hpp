/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:24 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 17:53:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
        Intern(); 
        ~Intern(); 
       Intern(const Intern &copy);
       Intern &operator=(const Intern &other);

       class NoFormFoundException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "This Form don't exist!\n";
                }
       };
    
        AForm *makeForm(std::string name, std::string target);
};

#endif
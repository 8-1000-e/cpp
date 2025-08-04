/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:25:56 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 18:14:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern random;
    AForm* form;
    Bureaucrat bob("Bob", 1);

    try
    {
        form = random.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        bob.signForm(*form);
        form->execute(bob);
        delete form;
    }
    catch (std::exception &e)
    {
        delete form;
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n\n\n\n\n";

    try
    {
        form = random.makeForm("shrubbery creation", "Garden");
        std::cout << *form << std::endl;
        bob.signForm(*form);
        form->execute(bob);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n\n\n\n\n";
    
    try
    {
        form = random.makeForm("presidential pardon", "Marvin");
        std::cout << *form << std::endl;
        bob.signForm(*form);
        form->execute(bob);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n\n\n\n\n";

    try
    {
        form = random.makeForm("unknown form", "Nobody");
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

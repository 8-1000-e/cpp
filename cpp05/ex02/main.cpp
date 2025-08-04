/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:25:56 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 17:27:02 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // AForm a;

    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat middle("Middle", 70);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Ford");

        intern.signForm(shrub);
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        try 
        {
            intern.executeForm(shrub);
        }
        catch (std::exception &e)
        {
            std::cout << e.what();
        }

        try 
        {
            ShrubberyCreationForm unSigned("forest");
            boss.executeForm(unSigned);
        }
        catch (std::exception &e)
        {
            std::cout << e.what();
        }
        

        boss.executeForm(shrub);
        boss.executeForm(robot);   
        boss.executeForm(pardon);  

        shrub.execute(boss);
        robot.execute(boss);
        pardon.execute(boss);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

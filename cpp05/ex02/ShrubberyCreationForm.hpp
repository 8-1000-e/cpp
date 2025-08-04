/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:47:23 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 15:31:55 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;        
    public:
       ShrubberyCreationForm(const std::string _target);
       ShrubberyCreationForm();
      ~ShrubberyCreationForm();
       ShrubberyCreationForm(const ShrubberyCreationForm &copy);
       ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    
       class GradeTooLowToExecException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too low to exec!\n";
                }
       };

       class FormNotSignedException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Form is not signed!\n";
                }
       };  

       class OpenErrorException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Error while openning file!\n";
                }
       };


       void execute(Bureaucrat const & executor) const;
};

#endif
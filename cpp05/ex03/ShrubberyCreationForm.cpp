/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:54:33 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 17:01:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target): AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("UnNammed")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), target(copy.target)
{
    if (copy.getSigned())
        this->beSigned(Bureaucrat("NoName", copy.getGradeSign()));
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        if (other.getSigned())
            this->beSigned(Bureaucrat("NoName", this->getGradeSign()));
    }
    return *this;
}


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowToExecException();
    else
    {
        std::string filename = target + "_shrubbery";
        std::ofstream file(filename.c_str());
        
        if (!file) 
            throw OpenErrorException();
        else
        {
            file << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        "<< "\\\\\\" << "////\n         |||/\\\n         |||/\n         |||||\n   .....//||||...." << std::endl;
            file << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        "<< "\\\\\\" << "////\n         |||/\\\n         |||/\n         |||||\n   .....//||||...." << std::endl;
            file << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        "<< "\\\\\\" << "////\n         |||/\\\n         |||/\n         |||||\n   .....//||||...." << std::endl;
            file << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        "<< "\\\\\\" << "////\n         |||/\\\n         |||/\n         |||||\n   .....//||||...." << std::endl;
                
            file.close();
        }
    }
}


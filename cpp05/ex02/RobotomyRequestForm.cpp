/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:40:24 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 18:09:00 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string _target): AForm("RobotomyRequestForm", 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("UnNammed")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), target(copy.target)
{
    if (copy.getSigned())
        this->beSigned(Bureaucrat("NoName", copy.getGradeSign()));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        if (other.getSigned())
            this->beSigned(Bureaucrat("NoName", this->getGradeSign()));
    }
    return *this;
}


void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    srand(time(0));
    if (!this->getSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowToExecException();
    else if (rand() % 2 == 0)
        throw RobotFailledException();
    else
        std::cout << "Bzzzzzz... Brrrzzzzz..." << std::endl << target << " has been robotomized successfully!\n";
}


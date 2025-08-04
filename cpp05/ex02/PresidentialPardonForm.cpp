/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:46:45 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 18:08:33 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string _target): AForm("PresidentialPardonForm", 25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("UnNammed")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), target(copy.target)
{
    if (copy.getSigned())
        this->beSigned(Bureaucrat("NoName", copy.getGradeSign()));
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        if (other.getSigned())
            this->beSigned(Bureaucrat("NoName", this->getGradeSign()));
    }
    return *this;
}


void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowToExecException();
    else
        std::cout << target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}

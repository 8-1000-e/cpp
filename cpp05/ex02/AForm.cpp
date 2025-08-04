/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:41:27 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 16:59:26 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string _name, const int reqSign, const int reqExec): Name(_name), gradeSign(reqSign), gradeExec(reqExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
    isSigned = false;
}

AForm::AForm(): Name("UnNammed"), gradeSign(150), gradeExec(150)
{
    isSigned = false;
}

AForm::~AForm()
{
}
AForm::AForm(const AForm &copy):Name(copy.Name), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{
    isSigned = copy.isSigned;
}

AForm&   AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string   AForm::getName() const
{
    return Name;
}

bool                AForm::getSigned() const
{
    return isSigned;
}

int           AForm::getGradeExec() const
{
    return gradeExec;
}

int           AForm::getGradeSign() const
{
    return gradeSign;
}


std::ostream    &operator<<(std::ostream &out, const AForm &f)
{
    out << f.getName() << ", grade required to sign = " << f.getGradeSign() << ", grade required to execute = " << f.getGradeExec() << ", is AForm signed = " << f.getSigned() << "." << std::endl;
    return out;
}


void                AForm::beSigned(Bureaucrat b)
{
    if (b.getGrade() > gradeSign)
        throw GradeTooLowToSignException();
    else
        isSigned = true;
}

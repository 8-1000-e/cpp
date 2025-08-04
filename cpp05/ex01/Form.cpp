/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:57:53 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 16:59:39 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string _name, const int reqSign, const int reqExec): Name(_name), gradeSign(reqSign), gradeExec(reqExec)
{
    std::cout << "Form constructor called" << std::endl;
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
    isSigned = false;
}

Form::Form(): Name("UnNammed"), gradeSign(150), gradeExec(150)
{
    std::cout << "Form default constructor called" << std::endl;
    isSigned = false;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}
Form::Form(const Form &copy):Name(copy.Name), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{
    std::cout << "Form Copy constructor called" << std::endl; 
    isSigned = copy.isSigned;
}

Form&   Form::operator=(const Form &other)
{
    std::cout << "Form Copy assignment operator called" << std::endl; 
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string   Form::getName() const
{
    return Name;
}

bool                Form::getSigned() const
{
    return isSigned;
}

int           Form::getGradeExec() const
{
    return gradeExec;
}

int           Form::getGradeSign() const
{
    return gradeSign;
}


std::ostream    &operator<<(std::ostream &out, const Form &f)
{
    out << f.getName() << ", grade required to sign = " << f.getGradeSign() << ", grade required to execute = " << f.getGradeExec() << ", is Form signed = " << f.getSigned() << "." << std::endl;
    return out;
}


void                Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() > gradeSign)
        throw GradeTooLowToSignException();
    else
        isSigned = true;
}

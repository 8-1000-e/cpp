/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:30:22 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 12:55:34 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade): Name (_name)
{
    std::cout << "Bureaucrat constructor called" << std::endl; 

    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    Grade = _grade;
}

Bureaucrat::Bureaucrat(): Name ("UnNammed")
{
    std::cout << "Default Bureaucrat constructor called" << std::endl; 
    Grade = 150;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): Name(copy.Name)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl; 
    Grade = copy.Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl; 
    if (this != &other)
        Grade = other.Grade;
    return *this;
}

int         Bureaucrat::getGrade() const
{
    return Grade;
}

const std::string       Bureaucrat::getName() const
{
    return Name;
}

void         Bureaucrat::UpGrade()
{
    Grade -= 1;
    if (Grade < 1)
        throw GradeTooHighException();
}

void         Bureaucrat::DownGrade()
{
    Grade += 1;
    if (Grade > 150)
        throw GradeTooLowException();
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &f)
{
    out << f.getName() << ", bureaucrat grade " << f.getGrade() << "." << std::endl;
    return out;
}



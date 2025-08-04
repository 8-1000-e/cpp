/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:30:22 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 17:17:33 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade): Name (_name)
{

    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    Grade = _grade;
}

Bureaucrat::Bureaucrat(): Name ("UnNammed")
{
    Grade = 150;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): Name(copy.Name)
{
    Grade = copy.Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
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

void        Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
    }
    catch (std::exception &e)
    {
        std::cout << Name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << Name << " signed " << f.getName() << std::endl;
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &f)
{
    out << f.getName() << ", bureaucrat grade " << f.getGrade() << "." << std::endl;
    return out;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    std::cout << Name << " executed " << form.getName() << std::endl;
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
}


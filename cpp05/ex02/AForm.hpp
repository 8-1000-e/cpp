/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:57:48 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 18:09:57 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   Name;
        bool                isSigned;
        const int           gradeSign;
        const int           gradeExec;
    
    public:
       AForm(const std::string _name, const int reqSign, const int reqExec);
       AForm();
       virtual ~AForm();
       AForm(const AForm &copy);
       AForm &operator=(const AForm &other);
        
       class GradeTooHighException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too High, must be between 1 and 150 !\n";
                }
       };

       class GradeTooLowException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too low, must be between 1 and 150 !\n";
                }
       };

       class GradeTooLowToSignException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too low to sign!\n";
                }
       };       

       const std::string     getName() const;
       bool             getSigned() const;
       int        getGradeSign() const;
       int        getGradeExec() const;

       void    beSigned(Bureaucrat b);
       virtual void execute(Bureaucrat const & executor) const = 0;
};

    std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:57:48 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 15:14:50 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   Name;
        bool                isSigned;
        const int           gradeSign;
        const int           gradeExec;
    
    public:
       Form(const std::string _name, const int reqSign, const int reqExec);
       Form();
      ~Form();
       Form(const Form &copy);
       Form &operator=(const Form &other);
        
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
};

    std::ostream &operator<<(std::ostream &out, const Form &f);

#endif

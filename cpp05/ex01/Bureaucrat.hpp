/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:09:35 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 13:45:35 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string Name;
        int               Grade;
    
    public:
       Bureaucrat(const std::string _name, int grade);
       Bureaucrat();
      ~Bureaucrat();
       Bureaucrat(const Bureaucrat &copy);
       Bureaucrat &operator=(const Bureaucrat &other);
        
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
       
       int                getGrade() const;
       const std::string  getName() const;
       
       void               UpGrade();
       void               DownGrade();

       void               signForm(Form f);
};
    
    std::ostream &operator<<(std::ostream &out, const Bureaucrat &f);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:52:43 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 15:39:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;        
    public:
       RobotomyRequestForm(const std::string _target);
       RobotomyRequestForm();
      ~RobotomyRequestForm();
       RobotomyRequestForm(const RobotomyRequestForm &copy);
       RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    
       class GradeTooLowToExecException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too low to exec!\n";
                }
       };

       class FormNotSignedException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Form is not signed!\n";
                }
       };  

       class RobotFailledException : public std::exception
       {
            public:
                virtual const char *what() const throw()
                {
                    return "Robotomy failed!\n";
                }
       };  

       void execute(Bureaucrat const & executor) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:53:32 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 15:46:10 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;        
    public:
       PresidentialPardonForm(const std::string _target);
       PresidentialPardonForm();
      ~PresidentialPardonForm();
       PresidentialPardonForm(const PresidentialPardonForm &copy);
       PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    
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

       void execute(Bureaucrat const & executor) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:23:10 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 13:57:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Marc", 10);
        Bureaucrat b2("Alex", 100);
        Bureaucrat b3;
        Bureaucrat b4(b2);
        b3 = b1;
        std::cout << b1;
        std::cout << b2;
        std::cout << b3;
        std::cout << b4;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n\n\n\n\n\n\n";

    try
    {
       Bureaucrat m1("Antoine", -100); 
       std::cout << m1;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n\n";
    
    try
    {
        Bureaucrat m2("Jean", 1000); 
        std::cout << m2;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n\n\n\n\n\n\n";
    try
    {
        Bureaucrat b1("Marc", 10);
        Form f1("contrat", 10, 100);
        Form f2("contrat2", 1, 10);
        Form f3 = f1;
        Form f4(f2);
        std::cout << f1;
        std::cout << f2;
        std::cout << f3;
        std::cout << f4;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n\n";
    
        try
    {
       Form m1("MauvaisContrat", -100, 1000); 
       std::cout << m1;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n\n";
    
    try
    {
        Form m2("EncorePlusMauvaisContrat", 1000, 10); 
        std::cout << m2;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n\n\n\n\n\n\n";

    Bureaucrat benoit("Benoit", 10);   
    Form contratBon("contrat", 10, 100);
    Form contratPasBon("contrat2", 1, 10);

    std::cout << "\n\n\n";

    benoit.signForm(contratBon);
    benoit.signForm(contratPasBon);
    benoit.signForm(contratBon);
}

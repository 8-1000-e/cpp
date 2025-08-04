/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:23:10 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/04 12:56:04 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
}

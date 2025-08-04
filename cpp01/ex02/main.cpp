/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:38:53 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/04 14:57:17 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Adresse de str :                  " << &str << std::endl;
    std::cout << "Adresse contenue dans stringPTR : " << stringPTR << std::endl;
    std::cout << "Adresse contenue dans stringREF : " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Valeur de str :                   " << str << std::endl;
    std::cout << "Valeur pointée par stringPTR :    " << *stringPTR << std::endl;
    std::cout << "Valeur référencée par stringREF : " << stringREF << std::endl;

}
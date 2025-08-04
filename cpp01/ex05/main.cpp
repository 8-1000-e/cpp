/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:36:02 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/04 16:56:45 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl h;

    std::cout << "Testing 'DEBUG' level:" << std::endl;
    h.complain("DEBUG");

    std::cout << "\nTesting 'INFO' level:" << std::endl;
    h.complain("INFO");

    std::cout << "\nTesting 'WARNING' level:" << std::endl;
    h.complain("WARNING");

    std::cout << "\nTesting 'ERROR' level:" << std::endl;
    h.complain("ERROR");

    std::cout << "\nTesting a non-existent level:" << std::endl;
    h.complain("NON_EXISTENT");
}

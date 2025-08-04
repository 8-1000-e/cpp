/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:36:02 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/07 15:20:14 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl h;

    if (ac != 2)
        std::cout << "Error: need 1 argument" << std::endl;
    else if (ac == 2)
        h.complain(av[1]);
}

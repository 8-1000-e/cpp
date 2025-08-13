/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:14:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/11 15:43:09 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Only 1 arguments required !" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange bit(argc == 2 ? argv[1] : "");
        bit.loadFile();
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
}

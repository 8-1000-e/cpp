/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:43:52 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/12 21:22:41 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
        return 1;
    }
    try
    {
        RPN expression (argv[1]);
    }
    catch (std::exception const &e)
    {
        std::cout << e.what();
    }
}
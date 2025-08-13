/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:28:23 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/07 15:01:24 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span longsp(100000);

    std::vector<int> toInsert;
    for (int i = 0; i < 100000; ++i)
        toInsert.push_back(i);

    try
    {
        longsp.fillSpan(toInsert.begin(), toInsert.end());
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << longsp.shortestSpan() << std::endl;
    std::cout << longsp.longestSpan() << std::endl;
    try
    {
        longsp.addNumber(10);
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }

    Span shortsp;
    try
    {
        shortsp.addNumber(1);    
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << shortsp.shortestSpan() << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        std::cout << shortsp.longestSpan() << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }

}
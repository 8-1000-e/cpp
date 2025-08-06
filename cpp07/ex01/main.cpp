/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:53:19 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/06 12:05:22 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    up(int &i)
{
    i++;
}


void    Charup(char &i)
{
    i++;
}


void    constUp(const char &i)
{
    std::cout << i << " is const" << std::endl;
}

int main()
{
    int IntArray[5] = {1, 2, 3, 4, 5};
    char CharArray[5] = {'a', 'b', 'c', 'd', 'e'};
    const char ConstCharArray[5] = {'v', 'w', 'x', 'y', 'z'};

    ::iter(IntArray, 5, up);
    std::cout << "new IntArray = ";
    for (size_t i = 0; i < 5; i++)
        std::cout << IntArray[i] << ", ";
    std::cout << std::endl;

    ::iter(CharArray, 5, Charup);
    std::cout << "new CharArray = ";
    for (size_t i = 0; i < 5; i++)
        std::cout << CharArray[i] << ", ";
    std::cout << std::endl;

    ::iter(ConstCharArray, 5, constUp);
}
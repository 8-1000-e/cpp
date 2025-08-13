/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:51:45 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/08 12:13:01 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    try
    {
        std::vector<int>::const_iterator it = easyfind(v, 30);
        std::cout << *it << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what();
    }

    try
    {
        easyfind(v, -30);
    }
    catch(const std::exception &e)
    {
        std::cout << e.what();
    }
}
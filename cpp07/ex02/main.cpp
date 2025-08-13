/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:27:15 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/06 14:38:27 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.cpp"

int main()
{
    Array<int> arr1;
    std::cout << "Size arr1 = " << arr1.size() << std::endl;

    Array<int> arr2(5);
    std::cout << "Size arr2 = " << arr2.size() << std::endl;
    std::cout << "OG arr2: ";
    for (unsigned int i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i < arr2.size(); ++i)
        arr2[i] = i * 10;
    std::cout << "new arr2: ";
    for (unsigned int i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl << std::endl;

    Array<int> arr3(arr2);
    std::cout << "arr3(arr2): ";
    for (unsigned int i = 0; i < arr3.size(); ++i)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;


    arr3[0] = 999;
    std::cout << "arr3[0] = 999" << std::endl << "arr3:  ";
    for (unsigned int i = 0; i < arr3.size(); ++i)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;
    std::cout << "arr2[0] = " << arr2[0] << std::endl;

    
    Array<int> arr4;
    arr4 = arr2;
    std::cout << "\narr4 = arr2: ";
    for (unsigned int i = 0; i < arr4.size(); ++i)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;

    std::cout << "arr4[1] = 888\n";
    arr4[1] = 888;
    for (unsigned int i = 0; i < arr4.size(); ++i)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;
    std::cout << "arr2[1] = " << arr2[1] << std::endl;


    std::cout << std::endl;
    std::cout << "arr[10]\n";
    try
    {
        std::cout << arr2[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "arr[-10]\n";
    try
    {
        std::cout << arr2[-10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Array<std::string> arrStr(2);
    arrStr[0] = "Hello";
    arrStr[1] = "World";
    for (unsigned int i = 0; i < arrStr.size(); ++i)
        std::cout << arrStr[i] << " ";
    std::cout << std::endl;
}

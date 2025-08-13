/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:50:26 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/08 13:21:12 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>
#include <algorithm>

void testWithMutantStack()
{
    std::cout << "--- MutantStack ---" << std::endl;

    MutantStack<int> mstack;
    mstack.push(100);
    mstack.push(200);
    mstack.push(300);
    mstack.push(400);
    mstack.push(500);

    std::cout << "Back: " << mstack.top() << std::endl;
    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(600);
    mstack.push(700);
    mstack.push(800);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Contents: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    it = std::find(mstack.begin(), mstack.end(), 100);
    if (it != mstack.end())
        std::cout << "Found" << std::endl;
    else
        std::cout << "Did not find" << std::endl;
}

void testWithList()
{
    std::cout << std::endl << "--- std::list ---" << std::endl;

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);
    lst.push_back(500);

    std::cout << "Back: " << lst.back() << std::endl;
    lst.pop_back();

    std::cout << "Size: " << lst.size() << std::endl;

    lst.push_back(600);
    lst.push_back(700);
    lst.push_back(800);

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    std::cout << "Contents: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    it = std::find(lst.begin(), lst.end(), 100);
    if (it != lst.end())
        std::cout << "Found" << std::endl;
    else
        std::cout << "Did not find" << std::endl;
}

int main()
{
    testWithMutantStack();
    testWithList();
    return 0;
}


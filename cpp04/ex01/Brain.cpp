/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:41 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 16:01:43 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


std::string intToString(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl; 
    for(int i = 0; i < 100; i++)
        ideas[i] = "UndefinedIdea" + intToString(i);
}

Brain::Brain(std::string id[100])
{
    std::cout << "Brain Constructor called" << std::endl; 
    for(int i = 0; i < 100; i++)
        ideas[i] = id[i];
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;     
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain Copy constructor called" << std::endl;     
    for(int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        std::cout << "Brain Copy assignment operator called" << std::endl;
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

void    Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
    return ideas[index];
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:59:50 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/12 21:28:32 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    std::cout << "Error, program take 1 argument!" << std::endl;
}

RPN::RPN(std::string s)
{
    std::cout << solve(s) << std::endl;
}

RPN::~RPN() {}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

int RPN::isSign(char c)
{
    if (c == '-' || c == '+' || c == '/' || c == '*')
        return 1;
    return 0;
}

int RPN::parseString(std::string s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (!std::isdigit(s[i]) && !isSign(s[i]))
                return -1;
        }
        else if (s[i] != ' ' && s[i])
            return -1;
    }
    return 0;
}

int RPN::makeCalcul(char c)
{
    int second = stack.top(); stack.pop();
    int first = stack.top(); stack.pop();
    
    if (c == '-') return first - second;
    if (c == '+') return first + second;
    if (c == '*') return first * second;
    if (!second)
        throw DivisionBy0();
    return first / second;
}

int RPN::solve(std::string s)
{
    if (parseString(s) == -1)
        throw ParseError();

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (std::isdigit(s[i]))
            stack.push(s[i] - '0');
        else if (isSign(s[i]))
        {
            if (stack.size() < 2)
                throw ParseError();
            stack.push(makeCalcul(s[i]));
        }
    }
    if (stack.size() != 1)
        throw ParseError();
    return stack.top();
}

const char *RPN::ParseError::what() const throw()
{
    return "Error in expression !\n" ;
}

const char *RPN::DivisionBy0::what() const throw()
{
    return "Can't divide by 0!\n" ;
}
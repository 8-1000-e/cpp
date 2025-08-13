/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:54:53 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/12 21:28:07 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>


class RPN
{
    private:
        std::stack<int> stack;
        int solve(std::string s);
        int parseString(std::string s);
        int makeCalcul(char c);
        int isSign(char c);
        
    public:
        RPN();
        RPN(std::string s);
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &other);

        class ParseError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class DivisionBy0 : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif
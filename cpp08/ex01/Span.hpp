/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:01:15 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/07 14:58:27 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Span
{
    private:
        std::vector<int> v;
        unsigned int _size;
    
    public:
        Span(unsigned int n);
        Span();
        ~Span();
        Span(const Span &copy);
        Span&operator=(const Span &other);
        
        void    addNumber(int nb);
        void    fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan();
        int     longestSpan();

        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class SpanEmptyException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

};


#endif
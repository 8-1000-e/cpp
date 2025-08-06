/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:06:39 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/06 14:05:03 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *data;
        size_t _size;
    
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &other);
        T& operator[](unsigned int index);
        T& operator[](unsigned int index) const;

        class IndexTooHightException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
        
        size_t size() const;
};

#endif
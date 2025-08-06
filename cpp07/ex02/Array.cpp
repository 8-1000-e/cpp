/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:11:58 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/06 14:31:03 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): data(0), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n): data(new T[n]), _size(n)
{
    for(size_t i = 0; i < _size; i++)
        data[i] = T();
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
    _size = copy.size();
    data = new T[_size];
    for (size_t i = 0; i < _size; i++)
        data[i] = copy.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] data;
        _size = other.size();
        data = new T[_size];
        for (size_t i = 0; i < _size; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->size())
        throw IndexTooHightException();
    else
        return data[i];
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
    if (i >= this->size())
        throw IndexTooHightException();
    else
        return data[i];
}


template <typename T>
size_t  Array<T>::size() const
{
    return _size;
}

template <typename T>
const char *Array<T>::IndexTooHightException::what() const throw()
{
    return "Index is out of bounds!";
}
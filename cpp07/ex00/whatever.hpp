/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:23:01 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/06 11:41:54 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void    swap(T &v1, T &v2)
{
    T tmp;
    tmp = v1;
    v1 = v2;
    v2 = tmp;
}

template <typename T>
T    min(T v1, T v2)
{
    return v1 < v2 ? v1 : v2;
}

template <typename T>
T    max(T v1, T v2)
{
    return v1 > v2 ? v1 : v2;
}

#endif 
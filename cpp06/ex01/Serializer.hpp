/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:11:07 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/05 16:08:02 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
# include <stdint.h>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();        

    public:
        virtual ~Serializer() = 0;
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &other);

        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
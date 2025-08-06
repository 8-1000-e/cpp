/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:00:07 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/05 16:15:32 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d1;
    d1.id = 42;
    d1.name = "School";

    Data* ptr = &d1;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* ptr2 = Serializer::deserialize(raw);

    std::cout << "Og ptr:               " << ptr << std::endl;
    std::cout << "Serialized            " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;

    std::cout << "id = " << ptr2->id << " | name = " << ptr2->name << std::endl;
}

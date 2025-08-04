/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:12:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 14:50:03 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
        public:
        Dog(std::string t);
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &other);

        void    makeSound() const;

};

#endif
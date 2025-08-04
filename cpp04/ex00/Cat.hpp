/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:12:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 14:49:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
        public:
        Cat(std::string t);
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &other);

        void    makeSound() const;

};

#endif
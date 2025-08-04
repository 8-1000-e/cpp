/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:12:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 15:51:39 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
        private:
                Brain *brain;    
        
        public:
                Dog(std::string t);
                Dog();
                ~Dog();
                Dog(const Dog &copy);
                Dog &operator=(const Dog &other);
        
                void    makeSound() const;
                void    setIdea(int index, const std::string& idea);
                std::string getIdea(int index);

};

#endif
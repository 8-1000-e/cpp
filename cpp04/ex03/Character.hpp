/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:26:03 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/18 10:19:34 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private: 
        std::string Name;
        AMateria *inventory[4];
        AMateria **dropped;
        
    public:
        Character(std::string const &name);
        Character();
        ~Character();
        Character(const Character &copy);
        Character &operator=(const Character &other);

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        void expandDropped(AMateria *n);
        
        std::string const &getName() const;
    
};

#endif
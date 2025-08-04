/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:54:40 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/17 15:31:34 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *stack[4];

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &copy); 
        MateriaSource &operator=(const MateriaSource &other);
    
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const& type);
};

#endif
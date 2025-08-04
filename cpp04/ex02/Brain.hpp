/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:18:35 by edubois-          #+#    #+#             */
/*   Updated: 2025/06/14 16:01:08 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(std::string ideas[100]);
        ~Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &other);

        void            setIdea(int index, const std::string& idea);
        std::string     getIdea(int index);
};

#endif
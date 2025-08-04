/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:21:16 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/07 16:45:43 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

#include <iostream>
#include <fstream>

class Swap
{
private:
    std::string infile;
    std::string swap;
    std::string swaper;
    std::ofstream *outfile;
    void    setOutfile(std::ofstream *file);
    
public:
    Swap(std::string infile, std::string swap, std::string swaper);
    ~Swap();

    std::string     getInfile();
    std::string     getSwap();
    std::string     getSwaper();
    std::ofstream  &getOutfile();

    bool   openOutfile();

};



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:21:09 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 10:40:43 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Swap.hpp"

Swap::Swap(std::string infile, std::string swap, std::string swaper) :
    infile(infile), swap(swap), swaper(swaper) {}

Swap::~Swap()
{
    if (outfile)
        delete outfile;
}

std::string Swap::getInfile()
{
    return infile;
}

std::string Swap::getSwap()
{
    return swap;
}

std::string Swap::getSwaper()
{
    return swaper;
}
std::ofstream &Swap::getOutfile()
{
    return *outfile;
}


void    Swap::setOutfile(std::ofstream *file)
{
    outfile = file;
}


bool    Swap::openOutfile()
{
    setOutfile(NULL);
    outfile = new std::ofstream((getInfile() + ".replace").c_str());
    if (!outfile->is_open())
    {
        std::cout << "Error when opening outfile" << std::endl;
        return false;
    }
    setOutfile(outfile);
    return true;
}



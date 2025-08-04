/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:13:57 by edubois-          #+#    #+#             */
/*   Updated: 2025/04/08 12:00:09 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Swap.hpp"

int ft_strlen(std::string string)
{
    return (string.length());
}

bool fileExists(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    return file.good();
}

int countLines(const std::string& filename)
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return -1;
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(infile, line))
        ++lineCount;

    return lineCount;
}

void makeSwap(char **argv)
{
    Swap file(argv[1], argv[2], argv[3]);
    if (!file.openOutfile())
        return;

    std::ifstream infile(file.getInfile().c_str());
    if (!infile || !infile.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier d'entrée." << std::endl;
        return;
    }

    int totalLines = countLines(file.getInfile());
    if (totalLines == -1)
        return ;
    int currentLine = 0;
    std::string line;

    while (std::getline(infile, line))
    {
        currentLine++;
        for (size_t i = 0; i < line.length(); i++)
        {
            if (line.substr(i, file.getSwap().length()) == file.getSwap())
            {
                file.getOutfile() << file.getSwaper();
                i += file.getSwap().length() - 1;
            }
            else
                file.getOutfile() << line[i];
        }
        if (currentLine < totalLines)
            file.getOutfile() << std::endl;
    }
}


int main(int argc, char **argv)
{
    if (argc != 4 || !ft_strlen(argv[2]))
    {
        std::cout << "Error: wrong input" << std::endl;
        return (1);
    }
    if (!fileExists(argv[1]))   
    {
        std::cout << "Error: " << argv[1] << " file error" << std::endl;
        return (1);
    }
    makeSwap(argv);
}

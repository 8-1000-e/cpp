/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:10:16 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/11 15:44:02 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): file("")
{
    try
    {
        openStats();
    }
    catch (std::exception const &e)
    {
        throw OpenCSVErrorExecption();        
    }
}


BitcoinExchange::BitcoinExchange(const std::string name): file(name) 
{
    try
    {
        openStats();
    }
    catch (std::exception const &e)
    {
        throw OpenCSVErrorExecption();        
    }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): file(copy.file)
{
    tab = copy.tab;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        file = other.file;
        tab = other.tab;
    }
    return *this;
}

float BitcoinExchange::stringToFloat(const std::string& s)
{
    std::stringstream ss(s);
    float result = 0.0f;
    ss >> result;
    return result;
}

int    BitcoinExchange::parseLigneFile(std::string ligne)
{
    int i = 0;
    for (; i < 10 && ligne[i]; i++);
    if (ligne.length() < 14 || i != 10 || ligne[i] != ' ' || ligne[i+1] != '|' || ligne[i+2] != ' ')
    {
        std::cout << "Error: bad input => " << ligne << std::endl;
        return -1;
    }
    if (ligne[4] != '-' || atoi(ligne.substr(0, 4).c_str()) <= 0)
    {
        std::cout << "Error: bad input => " << ligne << std::endl;
        return -1;
    }
    if (ligne[7] != '-' || atoi(ligne.substr(5, 2).c_str()) <= 0 || atoi(ligne.substr(5, 2).c_str()) > 12)
    {
        std::cout << "Error: bad input => " << ligne << std::endl;
        return -1;
    }
    if (atoi(ligne.substr(8, 2).c_str()) <= 0 || atoi(ligne.substr(8, 2).c_str()) > 31)
    {
        std::cout << "Error: bad input => " << ligne << std::endl;
        return -1;
    }
    
    for (; ligne[i] && ligne[i] != '\n'; i++);
    float nb = stringToFloat(ligne.substr(12, ligne.length()).c_str());
    if (nb < 0 || nb > 1000)
    {
        std::cout << (nb < 0 ? "Error: not a positive number." : "Error: too large a number.") << std::endl;
        return -1;
    }
    if (nb == 0)
    {
        for (int j = 12; ligne[j] && ligne[j] != '\n'; j++)
        {
            if (ligne[j] != '0')
            {
                std::cout << "Error: bad input => " << ligne << std::endl;
                return -1;
            }
        }
    }
    return 0;
}

void    BitcoinExchange::loadFile()
{
    std::ifstream f(file.c_str());

    if (!f.is_open())
        throw OpenErrorExecption();
    std::string ligne;
    std::getline(f, ligne);
    if (ligne != "date | value")
        throw BadFileHeaderExecption();
    while (std::getline(f, ligne))
    { 
        if (parseLigneFile(ligne) == -1)
            continue ;
        std::string date = ligne.substr(0, 10);
        float ogValue = stringToFloat(ligne.substr(12, ligne.length()));
        std::map<std::string, float>::iterator it = tab.lower_bound(date);
        if (it == tab.end())
            it--;
        else if (it->first != date)
        {
            if (it == tab.begin())
                std::cout << "Error: no lower date than " << date << std::endl;
            else
            {
                it--;
                float value = it->second * ogValue;
                std::cout << date << " => " << ogValue << " = " << value << std::endl;
            }
        }
        else
            std::cout << date << " => " << ogValue << " = " << ogValue * tab[date] << std::endl;
    }
}

void    BitcoinExchange::parseLigneCSV(std::string ligne)
{
    int i = 0;
    for (; i < 10 && ligne[i]; i++);
    if (i != 10 || ligne[i] != ',')
        throw CSVModifiedExecption();
    if (ligne[4] != '-' || atoi(ligne.substr(0, 4).c_str()) <= 0)
        throw CSVModifiedExecption();
    if (ligne[7] != '-' || atoi(ligne.substr(5, 2).c_str()) <= 0 || atoi(ligne.substr(5, 2).c_str()) > 12)
        throw CSVModifiedExecption();
    if (atoi(ligne.substr(8, 2).c_str()) <= 0 || atoi(ligne.substr(8, 2).c_str()) > 31)
        throw CSVModifiedExecption();
    
    for (; ligne[i] && ligne[i] != '\n'; i++);
    if (stringToFloat(ligne.substr(11, ligne.length()).c_str()) < 0)
        throw CSVModifiedExecption();
    if (stringToFloat(ligne.substr(11, ligne.length()).c_str()) == 0)
        for (int j = 11; ligne[j] && ligne[j] != '\n'; j++)
            if (ligne[j] != '0')
                throw CSVModifiedExecption();
}

void    BitcoinExchange::openStats()
{
    std::ifstream file("data.csv");

    if (!file.is_open())
        throw OpenCSVErrorExecption();

    std::string ligne;
    std::getline(file, ligne);
    if (ligne != "date,exchange_rate")
        throw CSVModifiedExecption();
    while (std::getline(file, ligne))
    { 
        parseLigneCSV(ligne);
        tab[ligne.substr(0, 10)] = stringToFloat(ligne.substr(11, ligne.length()));
    }
}

const char *BitcoinExchange::OpenErrorExecption::what() const throw()
{
    return "Error could not open file.";
}

const char *BitcoinExchange::BadFileHeaderExecption::what() const throw()
{
    return "Wrong File header!";
}

const char *BitcoinExchange::OpenCSVErrorExecption::what() const throw()
{
    return "Error while opening CSV file!";
}

const char *BitcoinExchange::CSVModifiedExecption::what() const throw()
{
    return "CSV file has been modified!";
}
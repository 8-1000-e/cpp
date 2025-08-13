/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:59:44 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/11 13:45:17 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::string file;
        std::map<std::string, float> tab;
        void openStats();
        void parseLigneCSV(std::string ligne);
        int parseLigneFile(std::string ligne);
        float stringToFloat(const std::string& s);
        
        
        public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const std::string name);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        
        
        void loadFile();

        class BadFileHeaderExecption : public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
        
        class OpenErrorExecption : public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
        
        class OpenCSVErrorExecption : public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
        
        class CSVModifiedExecption : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
};

#endif


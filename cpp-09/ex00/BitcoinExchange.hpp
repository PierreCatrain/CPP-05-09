/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:24:35 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/02 04:35:31 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>
# include <algorithm> 
 

# define RED "\033[31m"
# define RESET "\033[0m"

class BitcoinExchange
{
    private :
        std::map<std::string, double> _map;

        bool IsOnly(const std::string str, const std::string charset);
        std::string Trim(const std::string& str);
        
        void GetData();
        void SetUpDataFile(std::ifstream& file);
        void HandleDataLine(const std::string& line, const int index,  std::ifstream& file);
        
        void SetUpFile(std::ifstream& file);
        void HandleLine(const std::string& line, const int index);
        bool IsDateValid(const std::string& date);
        bool IsValueValid(const std::string& value, const int border);
        bool IsOlder(const std::string mapDate, const std::string date);
        
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& cpy);
        ~BitcoinExchange();
        
        void Exchange(const std::string& filename);

        class BtcException : std::exception
        {
            public :
                virtual const char* what() const throw() { return ""; }
        };
};

#endif
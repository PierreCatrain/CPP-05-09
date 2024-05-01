/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:24:35 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 10:44:09 by picatrai         ###   ########.fr       */
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

class BitcoinExchange
{
    private :
        std::map<std::string, std::string> _map;

        bool IsOnly(const std::string str, const std::string charset);
        std::string trim(const std::string& str);
        
        void SetUpFile(std::ifstream& file);
        void HandleLine(const std::string& line);
        bool IsDateValid(const std::string& date);
        bool IsValueValid(const std::string& value);
        
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& cpy);
        ~BitcoinExchange();
        
        void Exchange(const std::string& filename);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:24:32 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/02 05:08:40 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
    *this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy)
{
    this->_map = cpy._map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::SetUpFile(std::ifstream& file)
{
    std::string line;
    
    if (!file.is_open())
    {
        std::cout << RED << "Error: file does not exist" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << RED << "Error: file is empty" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }

    std::getline(file, line);
    if (line != "date | value")
    {
        std::cout << RED << "Error: invalid file format" << RESET << std::endl;
        file.close();      
        throw BitcoinExchange::BtcException();
    }
}

std::string BitcoinExchange::Trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return ("");
    size_t last = str.find_last_not_of(' ');
    return (str.substr(first, (last - first + 1)));
}

bool BitcoinExchange::IsOnly(const std::string str, const std::string charset)
{
    bool find;

    for(size_t i = 0; i < str.size(); i++)
    {
        find = false;
        for (size_t j = 0; j < charset.size(); j++)
        {
            if (str[i] == charset[j])
                find = true;
        }
        if (find == false)
            return (false);
    }
    return (true);
}

bool BitcoinExchange::IsDateValid(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (!IsOnly(year, "0123456789") || !IsOnly(month, "0123456789") || !IsOnly(day, "0123456789"))
        return (false);

    int yearInt = std::atoi(year.c_str());
    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());

    if (yearInt < 2009 || monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31)
        return (false);
    
    if (yearInt == 2009 && monthInt == 1 && dayInt == 1)
        return (false);

    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return (false);

    if (monthInt == 2 && ((yearInt % 4 == 0 && dayInt > 29) || (yearInt % 4 != 0 && dayInt > 28)))
        return (false);

    return (true);
}

bool BitcoinExchange::IsValueValid(const std::string& value, const int border)
{   
    if(value.empty())
        return (false);

    if (std::find(value.begin(), value.end(), '.') != value.end())
    {
        if (value.find('.') == 0 || value.find('.') == value.size() - 1 || std::find(value.begin() + value.find('.') + 1, value.end(), '.') != value.end())
            return (false);
    }
    
    if (!IsOnly(value, "0123456789."))
        return (false);

    double valueDouble = std::strtod(value.c_str(), NULL);

    if (valueDouble < 0 || (border == 1 && valueDouble > 1000.0))
        return (false);
    return (true);
}

bool BitcoinExchange::IsOlder(const std::string mapDate, const std::string date)
{

    int date_year = std::atoi((date.substr(0, 4)).c_str());
    int date_month = std::atoi((date.substr(5, 2)).c_str());
    int date_day = std::atoi((date.substr(8, 2)).c_str());

    int mapDate_year = std::atoi((mapDate.substr(0, 4)).c_str());
    int mapDate_month = std::atoi((mapDate.substr(5, 2)).c_str());
    int mapDate_day = std::atoi((mapDate.substr(8, 2)).c_str());

    if (mapDate_year < date_year)
        return (true);
    if (mapDate_year <= date_year && mapDate_month < date_month)
        return (true);
    if (mapDate_year <= date_year && mapDate_month <= date_month && mapDate_day <= date_day)
        return (true);
     
    return (false);
}

void BitcoinExchange::HandleLine(const std::string& line, const int index)
{
    size_t delim = line.find('|');
    if (delim == std::string::npos)
    {
        std::cout << RED << "Error: (line " << index << ") bad input => " << line << RESET << std::endl;
        return ;
    }
    std::string date = Trim(line.substr(0, delim));
    std::string value = Trim(line.substr(delim + 1));

    if (this->IsDateValid(date) == false)
    {
        if (date.empty())
            std::cout << RED << "Error: (line " << index << ") invalid date" << RESET << std::endl;
        else
            std::cout << RED << "Error: (line " << index << ") invalid date => " << date << RESET << std::endl;
        return ;
    }

    if (this->IsValueValid(value, 1) == false)
    {
        if (value.empty())
            std::cout << RED << "Error: (line " << index << ") invalid value" << RESET << std::endl;
        else
            std::cout << RED << "Error: (line " << index << ") invalid value => " << value << RESET << std::endl;
        return ;
    }
    
    std::map<std::string, double>::iterator Closest = this->_map.begin();
    for (std::map<std::string, double>::iterator it = this->_map.begin(); it != this->_map.end(); it++)
    {
        if (this->IsOlder(it->first, date))
            Closest = it;
    }
    std::cout << date << " => " << value  << " = " <<  (std::strtod(value.c_str(), NULL) * Closest->second) << std::endl;
    std::cout << "for " << Closest->first << std::endl;
}

void  BitcoinExchange::SetUpDataFile(std::ifstream& file)
{
    std::string line;
    
    if (!file.is_open())
    {
        std::cout << RED << "Error: datafile does not exist" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << RED << "Error: datafile is empty" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }

    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        std::cout << RED << "Error: invalid datafile format" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }
}

void BitcoinExchange::HandleDataLine(const std::string& line, const int index, std::ifstream& file)
{
    size_t delim = line.find(',');
    if (delim == std::string::npos)
    {
        std::cout << RED << "Error: line " << index << " is invalid in datafile" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }
    std::string date = line.substr(0, delim);
    std::string value = line.substr(delim + 1);

    if (this->IsDateValid(date) == false)
    {
        std::cout << RED << "Error: line " << index << " is invalid in datafile" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }

    if (this->IsValueValid(value, 0) == false)
    {
        std::cout << RED << "Error: line " << index << " is invalid in datafile" << RESET << std::endl;
        file.close();
        throw BitcoinExchange::BtcException();
    }
    this->_map.insert(std::make_pair(date, std::strtod(value.c_str(), NULL)));
}

void BitcoinExchange::GetData()
{
    std::ifstream   file("data.csv");
    std::string line;
    int index = 2;

    this->_map.clear();
    this->SetUpDataFile(file);
    while (std::getline(file, line))
    {
        this->HandleDataLine(line, index, file);
        index++;
    }
    file.close();
}

void BitcoinExchange::Exchange(const std::string& filename)
{
    try
    {
        std::ifstream   file(filename.c_str());
        std::string     line;
        int index;

        this->GetData();
        this->SetUpFile(file);
        index = 2;
        while (std::getline(file, line))
        {
            this->HandleLine(line, index);
            index++;
        }
        file.close();
    }
    catch(BitcoinExchange::BtcException& e) {}
}
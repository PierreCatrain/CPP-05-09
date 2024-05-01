/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:24:32 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 11:13:38 by picatrai         ###   ########.fr       */
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
        std::cout << "Error: file does not exist" << std::endl;
        exit(1);
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty" << std::endl;
        exit(1);
    }

    std::getline(file, line);
    if (line != "date | value")
    {
        std::cout << "Error: invalid file format" << std::endl;
        exit(1);
    }
}

std::string BitcoinExchange::trim(const std::string& str)
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

    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return (false);

    if (monthInt == 2 && ((yearInt % 4 == 0 && dayInt > 29) || (yearInt % 4 != 0 && dayInt > 28)))
        return (false);

    return (true);
}

bool BitcoinExchange::IsValueValid(const std::string& value)
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

    if (valueDouble < 0 || valueDouble > 1000.0)
        return (false);
    return (true);
}

// string BitcoinExchange::previousDate(const string& date) {
//     int year = ft_stoi(date.substr(0, 4));
//     int month = ft_stoi(date.substr(5, 2));
//     int day = ft_stoi(date.substr(8, 2));

//     // Days in each month (for non-leap years)
//     int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//     if (isLeapYear(year)) {
//         daysInMonth[2] = 29; // February has 29 days in a leap year
//     }

//     // Decrement the day
//     day--;

//     // Check if day is 0 (previous month)
//     if (day == 0) {
//         month--;

//         // Check if month is 0 (December)
//         if (month == 0) {
//             month = 12;
//             year--;
//         }

//         day = daysInMonth[month];
//     }

//     // Format the previous date
//     string newYear = ft_to_string(year);
//     string newMonth = (month < 10) ? "0" + ft_to_string(month) : ft_to_string(month);
//     string newDay = (day < 10) ? "0" + ft_to_string(day) : ft_to_string(day);

//     return newYear + "-" + newMonth + "-" + newDay;
// }

void BitcoinExchange::HandleLine(const std::string& line)
{
    size_t delim = line.find('|');
    if (delim == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }
    std::string date = trim(line.substr(0, delim));
    std::string value = trim(line.substr(delim + 1));

    if (this->IsDateValid(date) == false)
    {
        if (date.empty())
            std::cout << "Error: invalid date" << std::endl;
        else
            std::cout << "Error: invalid date => " << date << std::endl;
        return ;
    }

    if (this->IsValueValid(value) == false)
    {
        if (value.empty())
            std::cout << "Error: invalid value" << std::endl;
        else
            std::cout << "Error: invalid value => " << value << std::endl;
        return ;
    }
    try
    {
        std::map<std::string, std::string>::iterator it;
        std::string prevDate = date;
        it = this->_map.find(date);
        
        // std::cout << *it << std::endl;
        // while (it == this->_map.end())
        // {
        //     const std::string& currentDate = prevDate;
        //     prevDate = previousDate(currentDate);
        //     it = this->_map.find(prevDate);
        // }

        // std::cout << date << " => " << value  << " = "
        //     << ft_stod(it->second) * ft_stod(value) << std::endl;

    }
    catch (std::exception & e) {}
}


void BitcoinExchange::Exchange(const std::string& filename)
{
    std::ifstream   file(filename.c_str());
    std::string line;
    
    this->SetUpFile(file);
    while (std::getline(file, line))
    {
        this->HandleLine(line);
    }
    file.close();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:54:01 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/24 03:52:08 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
    *this = cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy)
{
    (void)cpy;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
	std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    std::string c;
    int i;
    float f;
    double d;
    
    if (str.size() == 1 && std::isprint(str[0]) && std::isdigit(str[0]) == 0)
    {
        c = str[0];
        std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return ;
    }

    for (int index = 0; index < 6; index++)
    {
        if(str == pseudo[index])
        {
            std::cout << "char: impossible" << std::endl;
		    std::cout << "int: impossible" << std::endl;
            if (index < 3)
            {
		        std::cout << "float: " << str << std::endl;
                std::cout << "double: " << pseudo[index + 3] << std::endl;
            }
            else
            {
                std::cout << "float: " << str << "f" << std::endl;
                std::cout << "double: " << str << std::endl;
            }
            return ;
        }
    }

    d = std::atof(str.c_str());
	f = static_cast<float>(d);
    i = static_cast<int>(d);
    if (i >= 0 && std::isprint(i))
    {
		c = "'";
		c += static_cast<char>(i);
		c += "'";
	}
    else
    {
        c = "Non displayable";
    }
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
    if (f - static_cast<int>(f) == 0)
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}
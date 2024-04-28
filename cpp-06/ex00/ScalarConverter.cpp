/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:54:01 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/28 05:43:47 by picatrai         ###   ########.fr       */
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

e_type ScalarConverter::find_type(std::string str, char *c, int *i, float *f, double *d)
{
    if (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]))
    {
        *c = str[0];
        return (CHAR);
    }

    int    j = 0;
    e_type type = INT;
    if (str[j] == '-' || str[j] == '+' )
        j++;
    for (int i = j; i < str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            type = NONE;
    }
    if (type == INT)
    {
        *i = atoi(str.c_str());
        return (INT);
    }



    int found = 0;
    type = FLOAT;
    j = 0;
    if (str.find('.') == std::string::npos || str[str.length() - 1] != 'f' || str.find('.') == 0 || str.find('.') == str.length() - 2)
        type = NONE;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i = j; i < static_cast<int>(str.length()) - 1; i++) 
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.' ) || found > 1)
            type = NONE;
    }
    if (type == FLOAT)
    {
        *f = atof(str.c_str());
        return (FLOAT);
    }


    j = 0;
    found = 0;
    type = DOUBLE;
    if (str.find('.') == std::string::npos || str.find('.') == 0 || str.find('.') == str.length() - 1)
        type = NONE;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i = j; i < static_cast<int>(str.length()); i++)
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i] ) && str[i] != '.') || found > 1)
            type = NONE;
    }
    if (type == DOUBLE)
    {
        *d = atof(str.c_str());
        return (DOUBLE);
    }
    return (NONE);    
}

void ScalarConverter::print_convert(e_type type, std::string str, char c, int i, float f, double d)
{
    if (type == CHAR)
    {
        std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return ;
    }
    else if (type == INT)
    {
        if (std::isprint(static_cast<char>(i)) && i < 127 && std::numeric_limits<int>::min() <= atof(str.c_str()) && std::numeric_limits<int>::max() >= atof(str.c_str()))
            std::cout << "char: " << static_cast<char>(i) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (std::numeric_limits<int>::min() <= atof(str.c_str()) && std::numeric_limits<int>::max() >= atof(str.c_str()))
        {
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;          
        }
        else
        {
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << atof(str.c_str()) << ".0f" << std::endl;
		    std::cout << "double: " << atof(str.c_str()) << ".0" << std::endl;
        }
        return ;
    }
    else if (type == FLOAT)
    {
        if (std::isprint(static_cast<char>(f)))
            std::cout << "char: " << static_cast<char>(f) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (std::numeric_limits<int>::min() <= atof(str.c_str()) && std::numeric_limits<int>::max() >= atof(str.c_str()))
		    std::cout << "int: " << static_cast<int>(f) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
        return ;
    }
    else if (type == DOUBLE)
    {
        if (std::isprint(static_cast<char>(d)))
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
		if (std::numeric_limits<int>::min() <= atof(str.c_str()) && std::numeric_limits<int>::max() >= atof(str.c_str()))
		    std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
        return ;
    }
    std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
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
    std::cout << "error: input is not a char, an int, a float or a double" << std::endl;
    return ;
}

void ScalarConverter::convert(std::string str)
{
    ScalarConverter tmp;
    char c;
    int i;
    float f;
    double d;
	e_type type = NONE;
    type = tmp.find_type(str, &c, &i, &f, &d);
    tmp.print_convert(type, str, c, i, f, d);
}
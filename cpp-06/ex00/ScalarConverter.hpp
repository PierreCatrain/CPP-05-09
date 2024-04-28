/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:54:10 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/28 05:45:19 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <fstream>

enum e_type
{
    NONE = 0,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
};

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& cpy);

        e_type find_type(std::string str, char *c, int *i, float *f, double *d);
        void print_convert(e_type type, std::string str, char c, int i, float f, double d);
    public :
        ~ScalarConverter();
        static void convert(std::string str);
};


#endif
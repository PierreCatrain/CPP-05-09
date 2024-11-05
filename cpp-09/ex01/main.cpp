/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:58:11 by picatrai          #+#    #+#             */
/*   Updated: 2024/11/05 06:40:34 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpn;
    if (argc != 2)
    {
        std::cerr << RED << "Error: wrong number of arguments" << RESET << std::endl;
        return (1);
    }
    rpn.Calcul(argv[1]);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:52:10 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 07:34:20 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange btc;
    if (argc != 2)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    btc.Exchange(argv[1]);
    return (0);
}

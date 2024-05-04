/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:42:02 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/03 08:33:34 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe PmM;
    if (argc == 1)
    {
        std::cerr << RED << "Error: no argument" << RESET << std::endl;
        return (1);
    }
    PmM.Sort(++argv);
    return (0);
}


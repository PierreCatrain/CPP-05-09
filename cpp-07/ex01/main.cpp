/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:34:58 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/29 04:18:48 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <cstring>

template<typename t>
void ft_put_array(t content)
{
    std::cout << content << std::endl;
}

int main(void)
{
    std::string array1[] = {"salut", "bonjour", "coucou"};
    int array2[] = {1, 3, 4, -23};
    
    ::iter(array1, sizeof(array1) / sizeof(array1[0]), &ft_put_array);
    ::iter(array2, sizeof(array2) / sizeof(array2[0]), &ft_put_array);
    return (0);
}
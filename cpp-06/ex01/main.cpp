/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:36:11 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/24 04:27:09 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data d;
    Data d2;
    uintptr_t res;
    uintptr_t res2;

    res = Serializer::serialize(&d);
    res2 = Serializer::serialize(&d2);
    
    if (&d == Serializer::deserialize(res))
        std::cout << "same" << std::endl;
    else
        std::cout << "different" << std::endl;
    
    std::cout << &d << std::endl;
    std::cout << Serializer::deserialize(res) << std::endl;    
    return (0);
}
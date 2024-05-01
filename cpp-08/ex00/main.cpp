/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:52:10 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 04:24:04 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	    std::cout << *i << std::endl;

	std::cout << std::endl;

    try
    {
        it = easyfind(v, -3);
        std::cout << "found " << *it << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "not found" << std::endl;
    }

    std::cout << std::endl;
    
    try
    {
        it = easyfind(v, 2);
        std::cout << "found " << *it << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "not found" << std::endl;
    }
	return 0;
}
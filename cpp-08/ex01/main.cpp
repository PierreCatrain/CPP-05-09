/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:36:34 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 03:58:45 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(1005);
        sp.addNumber(-6);
        sp.addNumber(6);
        sp.addNumber(9);
        sp.addNumber(12);
        sp.addNumber(17);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << std::endl;
        
        std::vector<int> v;

        for (int i = 0; i < 1000; i++)
            v.push_back(i);
        sp.addRange(v.begin(), v.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
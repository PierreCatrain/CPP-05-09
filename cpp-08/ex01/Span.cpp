/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:36:44 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 03:57:03 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n) : _n(n)
{   
}

Span::Span(const Span& cpy)
{
    *this = cpy;
}

Span& Span::operator=(const Span& cpy)
{
    this->_n = cpy._n;
    this->_v = cpy._v;
    this->_it = cpy._it;
    return (*this);
}

Span::~Span()
{
}
        
void Span::addNumber(int add)
{
    if (this->_v.size() < this->_n)
        this->_v.push_back(add);
    else
        throw SpanIsFullException();
}

unsigned int Span::shortestSpan()
{
    if (this->_v.size() < 2)
        throw SpanIsTooSmallException();
    std::vector<int> cpy(this->_v);
    std::sort(cpy.begin(), cpy.end());
    int span = *(cpy.begin() + 1) - *(cpy.begin());
    for (std::vector<int>::iterator it = cpy.begin(); it != (cpy.end() - 1); it++)
    {
        if ((*(it + 1) - *it) < span)
            span = (*(it + 1) - *it);
    }
    return (span);
}

unsigned int Span::longestSpan()
{
    if (this->_v.size() < 2)
        throw SpanIsTooSmallException();
    return (*std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end()));
}


void Span::addRange(std::vector<int>::iterator it_1, std::vector<int>::iterator it_2)
{
	if (this->_v.size() + std::distance(it_1, it_2) > this->_n)
		throw Span::SpanIsFullException();
	this->_v.insert(this->_v.end(), it_1, it_2);
}
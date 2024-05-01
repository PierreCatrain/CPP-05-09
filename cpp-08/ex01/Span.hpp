/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:36:52 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 03:43:17 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
    private :
        unsigned int _n;
        std::vector<int> _v;
	    std::vector<int>::iterator _it;

        Span();

    public :
        Span(unsigned int n);
        Span(const Span& cpy);
        Span& operator=(const Span& cpy);
        ~Span();

        void addNumber(int add);
        void addRange(std::vector<int>::iterator it_1, std::vector<int>::iterator it_2);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class SpanIsFullException : public std::exception
        {
			public:
                virtual const char* what() const throw() {return "span is full"; }
		};

        class SpanIsTooSmallException : public std::exception
        {
			public:
                virtual const char* what() const throw() {return "span is too small"; }
		};
};

#endif
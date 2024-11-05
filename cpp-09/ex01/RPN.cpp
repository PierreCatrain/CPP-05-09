/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:58:27 by picatrai          #+#    #+#             */
/*   Updated: 2024/11/05 06:52:58 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& cpy)
{
    *this = cpy;
}

RPN& RPN::operator=(const RPN& cpy)
{
    this->_stack = cpy._stack;
    return (*this);
}

RPN::~RPN()
{
}

bool RPN::IsOnly(const std::string str, const std::string charset)
{
    bool find;

    for(size_t i = 0; i < str.size(); i++)
    {
        find = false;
        for (size_t j = 0; j < charset.size(); j++)
        {
            if (str[i] == charset[j])
                find = true;
        }
        if (find == false)
            return (false);
    }
    return (true);
}

long long ft_div(long long nb1, long long nb2)
{
    if (nb2 == 0)
    {
        std::cout << RED << "Error: divide by zero is impossible" << RESET << std::endl;
        throw RPN::RPNexception();
    }
    return (nb1 / nb2);
}

long long ft_add(long long nb1, long long nb2)
{
    return (nb1 + nb2);
}

long long ft_sous(long long nb1, long long nb2)
{
    return (nb1 - nb2);
}

long long ft_mult(long long nb1, long long nb2)
{
    return (nb1 * nb2);
}

void RPN::do_op(const char c)
{
    char opp[] = {'/', '+', '-', '*'};
    long long (*ft_opp[])(long long, long long) = {ft_div, ft_add, ft_sous, ft_mult};
    long long nb1;
    long long nb2;
    long long res;

    if (this->_stack.size() < 2)
    {
        std::cout << RED << "Error: you tried to do an opp while having less than 2 numbers on the stack" << RESET << std::endl;
        throw RPN::RPNexception();
    }

    nb2 = this->_stack.top();
    this->_stack.pop();
    nb1 = this->_stack.top();
    this->_stack.pop();

    for (int index = 0; index < 4; index++)
    {
        if (opp[index] == c)
            res = ft_opp[index](nb1, nb2);
    }

    if (res > 2147483647 || res < -2147483648)
    {
        std::cout << RED << "Error: you will overflow after (" << nb1 << " " << c << " " << nb2 << ") so we stop the calcul for you" << RESET << std::endl;
        throw RPN::RPNexception();
    }
    this->_stack.push(static_cast<int>(res));
}

void RPN::Calcul(const std::string str)
{
    std::string digit = "0123456789";
    std::string opp = "/+-*";
    
    while (this->_stack.size() != 0)
        this->_stack.pop();
        
    if (this->IsOnly(str, "0123456789 /+-*") == false)
    {
        std::cout << RED << "Error: Unknown caracter" << RESET << std::endl;
        return ;
    }
    try
    {
        for (size_t index = 0; index < str.size(); index++)
        {
            if(digit.find(str[index]) != std::string::npos)
                this->_stack.push(str[index] - 48);
            else if (opp.find(str[index]) != std::string::npos)
                this->do_op(str[index]);
        }
        
        if (this->_stack.size() != 1)
            std::cout << RED << "Error: you didn't put enough opperation" << RESET << std::endl;
        else
            std::cout << GREEN << "RES => " << this->_stack.top() << RESET << std::endl;
    }
    catch (RPN::RPNexception& e) {}
}
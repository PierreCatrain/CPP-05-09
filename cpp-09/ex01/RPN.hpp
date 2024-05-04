/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:58:19 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/02 08:43:48 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"


class RPN
{
    private :
        std::stack<int> _stack;
        bool IsOnly(const std::string str, const std::string charset);
        void do_op(const char c);

    public :
        RPN();
        RPN(const RPN& cpy);
        RPN& operator=(const RPN& cpy);
        ~RPN();

        void Calcul(const std::string str);

        class RPNexception : std::exception
        {
            public :
                virtual const char* what() const throw() { return ""; }
        };
};

#endif
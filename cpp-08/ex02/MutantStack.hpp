/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:13:54 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 06:05:57 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>
# include <deque>
# include <iostream>


template<typename T, class Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container>
{
    public:

        MutantStack() {}
        
        ~MutantStack() {}

        MutantStack(const MutantStack& cpy)
        {
            *this = cpy;
        }
        
        MutantStack&    operator=(const MutantStack& cpy)
        {
            std::stack<T, Container>::operator=(cpy);
            return (*this);
        }

        typedef typename Container::iterator    iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }

        typedef typename Container::reverse_iterator    reverse_iterator;

        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }

        typedef typename Container::const_iterator    const_iterator;

        const const_iterator begin() const { return this->c.begin(); }
        const const_iterator end() const { return this->c.end(); }

        typedef typename Container::const_reverse_iterator    const_reverse_iterator;

        const const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
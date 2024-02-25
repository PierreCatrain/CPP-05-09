/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 03:41:39 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/25 07:53:19 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array
{
    private :
        unsigned int _n;
        T* _elements;
        
    public :

        Array() : _n(0), _elements(NULL)
        {
        }

        Array(unsigned int n) : _n(n), _elements(new T[n])
        {
        }

        Array(const Array& cpy)
        {
            *this = cpy;
        }

        Array& operator=(const Array& cpy)
        {
            if (this != &cpy)
            {
                if (this->_n != cpy._n)
                {
                    //delete[] this->_elements;
                    this->_elements = new T[cpy._n];
                    this->_n = cpy._n;
                }
                for (unsigned int i = 0; i < this->_n; i++)
                    this->_elements[i] = cpy._elements[i];
            }
            return (*this);
        }
        
        ~Array()
        {
            if (this->_elements != NULL)
                delete[] this->_elements;
        }
        
        T& operator[](unsigned int index)
        {
            if (index >= this->_n || index < 0)
                throw Array::OutOfBoundsException();
            return (this->_elements[index]);
        }
        
        unsigned int size() const
        {
            return (this->_n);
        }

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                { 
                    return ("Index is out of bounds");
                }
        };
};

#endif
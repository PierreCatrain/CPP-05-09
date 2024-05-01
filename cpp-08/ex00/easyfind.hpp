/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:31:54 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 03:01:14 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>


template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return (it);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:31:54 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/29 07:55:37 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

enum e_find
{
    FIND = 0,
    NOT_FIND,
};

// template <typename T>
// T    easyfind(T container, int value)
// {
//     T find = std::find(container.begin(), container.end(), value);
//     // if (std::find(container.begin(), container.end(), value) != container.end())
//     // {
//     //     std::cout << "Found." << std::endl;
//     //     return (FIND);
//     // }
//     // std::cout << "Not found." << std::endl;
//     // return (NOT_FIND);
// }

template <typename T>
e_find    easyfind(T container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
    {
        std::cout << "Found." << std::endl;
        return (FIND);
    }
    std::cout << "Not found." << std::endl;
    return (NOT_FIND);
}

#endif
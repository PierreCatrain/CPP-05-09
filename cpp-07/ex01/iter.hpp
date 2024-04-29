/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:35:11 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/29 04:17:51 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename t>
void    iter(t* array, int len, void (*f)(t content))
{
    for (int i = 0; i < len; i++)
        f(array[i]);
}

#endif
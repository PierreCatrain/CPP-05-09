/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:35:11 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/25 03:12:54 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename a, typename b, typename c>
void    iter(a address, b len, c ft)
{
    for (b i = 0; i < len; i++)
        ft(address[i]);
}

#endif
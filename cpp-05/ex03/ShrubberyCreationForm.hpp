/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:54:33 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 06:24:55 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# ifndef AFORM_HPP_INCLUDED
#  define AFORM_HPP_INCLUDED
#  include "AForm.hpp"
# endif

#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cpy);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat& executor) const;
};

#endif
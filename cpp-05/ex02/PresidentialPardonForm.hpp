/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:55:20 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 06:26:09 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# ifndef AFORM_HPP_INCLUDED
#  define AFORM_HPP_INCLUDED
#  include "AForm.hpp"
# endif

#include <iostream>

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& cpy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& cpy);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat& executor) const;
};

#endif
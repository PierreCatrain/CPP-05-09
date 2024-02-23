/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:54:59 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 06:25:58 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# ifndef AFORM_HPP_INCLUDED
#  define AFORM_HPP_INCLUDED
#  include "AForm.hpp"
# endif

#include <cstdlib>
#include <ctime>
#include <iostream>

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& cpy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& cpy);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& executor) const;
};

#endif
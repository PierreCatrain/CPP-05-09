/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 06:59:25 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 07:26:16 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# ifndef AFORM_HPP_INCLUDED
#  define AFORM_HPP_INCLUDED
#  include "AForm.hpp"
# endif

# ifndef PRESIDENTIALPARDONFORM_HPP_INCLUDED
#  define PRESIDENTIALPARDONFORM_HPP_INCLUDED
#  include "PresidentialPardonForm.hpp"
# endif

# ifndef ROBOTOMYREQUESTFORM_HPP_INCLUDED
#  define ROBOTOMYREQUESTFORM_HPP_INCLUDED
#  include "RobotomyRequestForm.hpp"
# endif

# ifndef SHRUBBERYCREATIONFORM_HPP_INCLUDED
#  define SHRUBBERYCREATIONFORM_HPP_INCLUDED
#  include "ShrubberyCreationForm.hpp"
# endif

#include <iostream>

class AForm;

class Intern
{
    public :
        Intern();
        Intern(const Intern& cpy);
        Intern& operator=(const Intern& cpy);
        ~Intern();
        
        AForm* makeForm(std::string name, std::string target);
        
};

#endif

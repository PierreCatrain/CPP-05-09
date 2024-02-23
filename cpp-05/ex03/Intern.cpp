/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 06:59:46 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 07:35:23 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& cpy)
{
    *this = cpy;
}

Intern& Intern::operator=(const Intern& cpy)
{
    (void)cpy;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string array_name[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *array_new[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    AForm *res = NULL;
	for (int i = 0; i < 3; i++)
    {
		if (array_name[i] == name) 
            res = array_new[i];
		else
            delete array_new[i];
	}
    if (res != NULL)
        std::cout << "Intern creates " << name << std::endl;
	else 
        std::cout << "Intern was not able to make " << name << std::endl;
	return (res);
}
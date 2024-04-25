/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:54:26 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 19:49:02 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Defaut", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy)
{
    *this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy)
{
    (void)cpy;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    this->canExec(executor);
    std::ofstream out;

	out.open(this->getName().c_str(), std::ofstream::trunc);

	out << std::endl;
    out << "    ()    " << std::endl;
    out << "    /\\    " << std::endl;
    out << "   / *\\   " << std::endl;
    out << "  / *  \\  " << std::endl;
	out << " / *  * \\ " << std::endl;
    out << "    []    " << std::endl;
    out.close();
}
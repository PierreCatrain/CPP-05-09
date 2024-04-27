/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:54:48 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/27 23:09:53 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy)
{
    *this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cpy)
{
    (void)cpy;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    this->canExec(executor);
    std::srand(std::time(NULL));

	std::cout << "* SOME DRILLING NOISES *" << std::endl;
	if (std::rand() % 2 == 0)
    {
		std::cout << this->getName() << " has been robotomized succesfully" << std::endl;
	}
    else
    {
		std::cout << "Failed to robotomized " << this->getName() << std::endl;
	}
}
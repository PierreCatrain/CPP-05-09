/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:33:45 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/27 23:17:23 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _grade_to_sign(100), _grade_to_exec(100)
{
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    if (_grade_to_sign > 150 || _grade_to_exec > 150)
        throw AForm::GradeTooLowException();
    else if (_grade_to_sign < 1 || _grade_to_exec < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& cpy) : _name(cpy._name), _signed(cpy._signed), _grade_to_sign(cpy._grade_to_sign), _grade_to_exec(cpy._grade_to_exec)
{
}
        
AForm& AForm::operator=(const AForm& cpy)
{
    this->_signed = cpy._signed;
    return (*this);
}
        
AForm::~AForm()
{
}

const std::string AForm::getName() const
{
    return (this->_name);
}

std::string AForm::getSigned() const
{
    if (this->_signed == false)
        return ("not signed");
    return ("signed");
}

int AForm::getGradeToSign() const
{
    return (this->_grade_to_sign);
}

int AForm::getGradeToExec() const
{
    return (this->_grade_to_exec);
}

void AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > this->_grade_to_sign)
    {
        std::cout << obj.getName() << " can't signed " << this->_name << " because ";
        throw AForm::GradeTooLowException();
    }
    std::cout << obj.getName() << " signed " << this->_name << std::endl;
    this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << " form is " << obj.getSigned() << ", requiered "<< obj.getGradeToSign() << " to be signed and " << obj.getGradeToExec() << " to be executed";
    return (os);
}

void AForm::canExec(const Bureaucrat& obj) const
{
    if (this->_signed == false)
    {
        std::cout << obj.getName() << " can't execute " << this->_name << " because ";
        throw AForm::NotSignedException();
    }
    if (obj.getGrade() > this->_grade_to_exec)
    {
        std::cout << obj.getName() << " can't execute " << this->_name << " because ";
        throw AForm::GradeTooLowException();
    }
}
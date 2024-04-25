/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:53:34 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 18:35:30 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _grade_to_sign(100), _grade_to_exec(100)
{
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    if (_grade_to_sign > 150 || _grade_to_exec > 150)
        throw Form::GradeTooLowException();
    else if (_grade_to_sign < 1 || _grade_to_exec < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& cpy) : _name(cpy._name), _signed(cpy._signed), _grade_to_sign(cpy._grade_to_sign), _grade_to_exec(cpy._grade_to_exec)
{
}
        
Form& Form::operator=(const Form& cpy)
{
    this->_signed = cpy._signed;
    return (*this);
}
        
Form::~Form()
{
}

std::string Form::getName() const
{
    return (this->_name);
}

std::string Form::getSigned() const
{
    if (this->_signed == false)
        return ("not signed");
    return ("signed");
}

int Form::getGradeToSign() const
{
    return (this->_grade_to_sign);
}

int Form::getGradeToExec() const
{
    return (this->_grade_to_exec);
}

void Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > this->_grade_to_sign)
    {
        std::cout << obj.getName() << " can't signed " << this->_name << " because ";
        throw Form::GradeTooLowException();
    }
    std::cout << obj.getName() << " signed " << this->_name << std::endl;
    this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.getName() << " form is " << obj.getSigned() << ", requiered "<< obj.getGradeToSign() << " to be signed and " << obj.getGradeToExec() << " to be executed";
    return (os);
}
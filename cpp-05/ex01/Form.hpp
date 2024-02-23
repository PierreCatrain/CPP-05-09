/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:53:37 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 04:25:44 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# ifndef BUREAUCRAT_HPP_INCLUDED
#  define BUREAUCRAT_HPP_INCLUDED
#  include "Bureaucrat.hpp"
# endif

#include <iostream>

class Bureaucrat;

class Form
{
    private :
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
    public :
        Form();
        Form(std::string name, int grade_to_sign, int grade_to_exec);
        Form(const Form& cpy);
        Form& operator=(const Form& cpy);
        ~Form();

        const std::string getName() const;
        std::string getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat& obj);
        

        class GradeTooHighException : std::exception
        {
        };

        class GradeTooLowException : std::exception
        {
        };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif
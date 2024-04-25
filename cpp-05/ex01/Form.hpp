/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:53:37 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 19:12:25 by picatrai         ###   ########.fr       */
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

        std::string getName() const;
        std::string getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat& obj);

        class GradeTooHighException : std::exception
        {
            public:
                virtual const char* what() const throw() { return "the grade is too high"; }
        };

        class GradeTooLowException : std::exception
        {
            public:
                virtual const char* what() const throw() { return "the grade is too low"; }
        };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif
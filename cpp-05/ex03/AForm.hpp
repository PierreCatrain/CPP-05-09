/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:33:58 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 06:27:18 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# ifndef BUREAUCRAT_HPP_INCLUDED
#  define BUREAUCRAT_HPP_INCLUDED
#  include "Bureaucrat.hpp"
# endif

#include <iostream>

class Bureaucrat;

class AForm
{
    private :
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
    public :
        AForm();
        AForm(std::string name, int grade_to_sign, int grade_to_exec);
        AForm(const AForm& cpy);
        AForm& operator=(const AForm& cpy);
        virtual ~AForm();

        const std::string getName() const;
        std::string getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat& obj);
        void canExec(const Bureaucrat& obj) const;

        virtual void execute(const Bureaucrat& executor) const = 0;
        

        class GradeTooHighException : std::exception
        {
        };

        class GradeTooLowException : std::exception
        {
        };

        class NotSignedException : std::exception
        {
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
#endif
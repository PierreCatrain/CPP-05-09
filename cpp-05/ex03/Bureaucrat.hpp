/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:32:30 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/27 23:23:53 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# ifndef AFORM_HPP_INCLUDED
#  define AFORM_HPP_INCLUDED
#  include "AForm.hpp"
# endif

#include <iostream>

class AForm;

class Bureaucrat
{
    private :
        const std::string _name;
        int _grade;
    
    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& cpy);
        Bureaucrat& operator=(const Bureaucrat& cpy);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void IncrementGrade();
        void DecrementGrade();

        void signForm(AForm& obj);

        void executeForm(AForm const & form);

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low"; }
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high"; }
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
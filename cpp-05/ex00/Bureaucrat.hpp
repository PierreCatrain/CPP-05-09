/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:00:45 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 18:35:10 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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
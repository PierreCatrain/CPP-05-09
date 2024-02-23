/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:00:45 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 02:37:46 by picatrai         ###   ########.fr       */
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

        const std::string getName() const;
        int getGrade() const;
        void IncrementGrade();
        void DecrementGrade();

        class GradeTooLowException : public std::exception
        {
        };

        class GradeTooHighException : public std::exception
        {
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:00:10 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 05:18:32 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "enter the grade you want" << std::endl;
        return (1);
    }
    Bureaucrat *Worker = new Bureaucrat("David", atoi(argv[1]));
    try
    {
        std::cout << *Worker << std::endl;
        for (int i = 0; i < 50; i++)
        {
            Worker->DecrementGrade();
            std::cout << *Worker << std::endl;
        }
        delete Worker;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "the grade is too high (max is 1)" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "the grade is too low (min is 150)" << std::endl;
    }
    delete Worker;
    return (0);
}
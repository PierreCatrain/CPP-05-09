/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:00:10 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 18:17:01 by picatrai         ###   ########.fr       */
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
    Bureaucrat Worker;
    try
    {
        Worker = Bureaucrat("David", atoi(argv[1]));
        std::cout << Worker << std::endl;
        for (int i = 0; i < 50; i++)
        {
            Worker.IncrementGrade();
            std::cout << Worker << std::endl;
        }
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
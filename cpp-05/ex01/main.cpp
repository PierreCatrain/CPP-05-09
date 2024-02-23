/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:45:57 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 05:19:51 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdlib.h>

int main(void)
{
    Bureaucrat* Worker = new Bureaucrat("David", 50);
    Form* F = new Form("blabla", 10, 150);
    try
    {
        std::cout << *Worker << std::endl;
        std::cout << *F << std::endl;
        Worker->signForm(*F);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "the grade is too high (max is 1)" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "the grade is too low (min is 150)" << std::endl;
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cout << "the grade is too high" << std::endl;
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cout << "the grade is too low" << std::endl;
    }
    delete Worker;
    delete F;
    return (0);
}
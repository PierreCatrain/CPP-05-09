/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:45:57 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 19:16:01 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdlib.h>

int main(void)
{
    try
    {
        Bureaucrat Worker = Bureaucrat("David", 150);
        Form F = Form("blabla", 10, 150);
        std::cout << Worker << std::endl;
        std::cout << F << std::endl;
        Worker.signForm(F);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
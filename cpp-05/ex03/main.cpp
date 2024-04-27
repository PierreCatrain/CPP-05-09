/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:32:19 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/27 23:28:23 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    AForm *A;
    AForm *B;
    try
    {
        Intern slave = Intern();
        A = slave.makeForm("asfdasdfasdfasdfas", "alors");
        B = slave.makeForm("RobotomyRequestForm", "test");
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::NotSignedException& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete A;
    delete B;
    return (0);
}
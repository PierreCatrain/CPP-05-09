/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:32:19 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/25 19:41:41 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat Worker = Bureaucrat("David", 5);
        ShrubberyCreationForm A = ShrubberyCreationForm("test");
        RobotomyRequestForm B = RobotomyRequestForm("robo");
        PresidentialPardonForm C = PresidentialPardonForm("president");
        std::cout << Worker << std::endl;
        Worker.signForm(A);
        Worker.signForm(B);
        Worker.signForm(C);
        Worker.executeForm(B);
        A.execute(Worker);
        B.execute(Worker);
        C.execute(Worker);
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
        // std::cout << e.what() << std::endl;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:32:19 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 06:55:55 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat* Worker = new Bureaucrat("David", 5);
    ShrubberyCreationForm* A = new ShrubberyCreationForm("test");
    RobotomyRequestForm* B = new RobotomyRequestForm("robo");
    PresidentialPardonForm* C = new PresidentialPardonForm("president");
    try
    {
        std::cout << *Worker << std::endl;
        Worker->signForm(*A);
        Worker->signForm(*B);
        Worker->signForm(*C);
        Worker->executeForm(*B);
        A->execute(*Worker);
        B->execute(*Worker);
        C->execute(*Worker);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "the grade is too high (max is 1)" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "the grade is too low (min is 150)" << std::endl;
    }
    catch (AForm::GradeTooHighException& e)
    {
        std::cout << "the grade is too high" << std::endl;
    }
    catch (AForm::GradeTooLowException& e)
    {
        std::cout << "the grade is too low" << std::endl;
    }
    catch (AForm::NotSignedException& e)
    {
        std::cout << "is not signed" << std::endl;
    }
    delete Worker;
    delete A;
    delete B;
    delete C;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:32:19 by picatrai          #+#    #+#             */
/*   Updated: 2024/02/23 07:37:46 by picatrai         ###   ########.fr       */
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
    Intern* slave = new Intern();
    AForm* A;
    AForm* B;
    try
    {
        A = slave->makeForm("asfdasdfasdfasdfas", "alors");
        B = slave->makeForm("RobotomyRequestForm", "test");
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
    delete slave;
    delete A;
    delete B;
    return (0);
}
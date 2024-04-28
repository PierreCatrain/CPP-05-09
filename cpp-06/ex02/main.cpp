/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 04:28:51 by picatrai          #+#    #+#             */
/*   Updated: 2024/04/28 06:33:09 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


Base* generate(void)
{
    int res;
    
    std::srand(std::time(NULL));
	res = std::rand() % 3;
    if (res == 0)
    {
        std::cout << "\"A\" has been genereted" << std::endl;
        return (new A());
    }
    else if (res == 1)
    {
        std::cout << "\"B\" has been genereted" << std::endl;
        return (new B());
    }
    std::cout << "\"C\" has been genereted" << std::endl;
    return (new C());
}

void identify(Base* p)
{
    A* a;
    B* b;
    C* c;

    a = dynamic_cast<A*>(p);
    if (a != NULL)
        std::cout << "it's \"A\"" << std::endl;
    b = dynamic_cast<B*>(p);
    if (b != NULL)
        std::cout << "it's \"B\"" << std::endl;
    c = dynamic_cast<C*>(p);
    if (c != NULL)
        std::cout << "it's \"C\"" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "it's \"A\"" << std::endl;
        (void)a;
        return ;
    }
    catch (std::exception & e)
    {
        ;
    }

    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "it's \"B\"" << std::endl;
        (void)b;
        return ;
    }
    catch (std::exception & e)
    {
        ;
    }

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "it's \"C\"" << std::endl;
        (void)c;
        return ;
    }
    catch (std::exception & e)
    {
        ;
    }
}

int main(void)
{
    Base *b;

    b = generate();
    identify(b);
    identify(*b);
    delete b;
    return (0);
}
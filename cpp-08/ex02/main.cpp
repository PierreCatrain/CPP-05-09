/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:14:35 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/01 06:04:16 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int main()
// {
// 	std::cout << "========== MUTANT STACK ==========" << std::endl;

// 	MutantStack<int> mstack;
// 	mstack.push(5); // 5
// 	mstack.push(17); // 17, 5
// 	std::cout << "Top: " << mstack.top() << std::endl;
// 	mstack.pop(); // 5
// 	std::cout << "Size: " << mstack.size() << std::endl;
// 	mstack.push(3); // 3, 5
// 	mstack.push(7); // 7, 3, 5
// 	mstack.push(737); // 737, 7, 3, 5
// 	mstack.push(0); // 0, 737, 7, 3, 5
// 	std::cout << "Size: " << mstack.size() << std::endl;
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	std::cout << "\nITERATE STACK:" << std::endl;
// 	while (it != ite) {
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	std::cout << "\nREVERSE ITERATE STACK:" << std::endl;
// 	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
// 	MutantStack<int>::reverse_iterator rite = mstack.rend();
// 	++rit;
// 	--rit;
// 	while (rit != rite) {
// 		std::cout << *rit << std::endl;
// 		++rit;
// 	}

// 	std::cout << "========== LIST ==========" << std::endl;
	
// 	std::list<int> ls;
// 	ls.push_back(5);
// 	ls.push_back(17);
// 	std::cout << "Back: " << ls.back() << std::endl;
// 	ls.pop_back();
// 	std::cout << "Size: " << ls.size() << std::endl;
// 	ls.push_back(3);
// 	ls.push_back(7);
// 	ls.push_back(737);
// 	ls.push_back(0);
// 	std::cout << "Size: " << ls.size() << std::endl;
// 	std::list<int>::iterator lit = ls.begin();
// 	std::list<int>::iterator lite = ls.end();
// 	++lit;
// 	--lit;
// 	std::cout << "\nITERATE LIST:" << std::endl;
// 	while (lit != lite) {
// 		std::cout << *lit << std::endl;
// 		++lit;
// 	}
// 	std::list<int> ls2(ls);
// 	std::cout << "\nREVERSE ITERATE LIST" << std::endl;	
// 	std::list<int>::reverse_iterator rlit = ls.rbegin();
// 	std::list<int>::reverse_iterator rlite = ls.rend();
// 	++rlit;
// 	--rlit;
// 	while (rlit != rlite) {
// 		std::cout << *rlit << std::endl;
// 		++rlit;
// 	}

// 	return 0;
// }

int main()
{
    std::cout << "========== MUTANT STACK ==========" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << std::endl;
    MutantStack<int>::reverse_iterator it_r = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite_r = --(mstack.rend());
    std::cout << *it_r << std::endl;
    std::cout << *ite_r << std::endl;
    MutantStack<int>::const_reverse_iterator it_cr = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator ite_cr = --(mstack.rend());
    // *ite_cr -= 1;
    std::cout << *it_cr << std::endl;
    std::cout << *ite_cr << std::endl;

    std::cout << "========== LIST ==========" << std::endl;

    std::list<int> clist;
    clist.push_back(5);
    clist.push_back(17);
    std::cout << clist.back() << std::endl;
    clist.pop_back();
    std::cout << clist.size() << std::endl;
    clist.push_back(3);
    clist.push_back(5);
    clist.push_back(737);
    //[...]
    clist.push_back(0);
    std::list<int>::iterator it_2 = clist.begin();
    std::list<int>::iterator ite_2 = clist.end();
    ++it_2;
    --it_2;
    while (it_2 != ite_2)
    {
    std::cout << *it_2 << std::endl;
    ++it_2;
    }
    std::list<int> dlist(clist);

    std::cout << std::endl;
    std::list<int>::reverse_iterator it_r_2 = clist.rbegin();
    std::list<int>::reverse_iterator ite_r_2 = --(clist.rend());
    std::cout << *it_r_2 << std::endl;
    std::cout << *(ite_r_2)<< std::endl;
    std::list<int>::const_reverse_iterator it_cr_2 = clist.rbegin();
    std::list<int>::const_reverse_iterator ite_cr_2 = --(clist.rend());
    // *ite_cr_2 -= 1;
    std::cout << *it_cr_2 << std::endl;
    std::cout << *ite_cr_2<< std::endl;
    return 0;
}
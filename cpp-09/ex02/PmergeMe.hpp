/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:42:16 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/04 09:23:07 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <iomanip>
# include <algorithm>
# include <list>
# include <vector>

# define RED "\033[31m"
# define RESET "\033[0m"

class PmergeMe
{
    private :
        std::vector<int> _vector;
        std::list<int> _list;

        void GetData(char **arg);
        bool IsOnly(const std::string str, const std::string charset);
        void IsDuplicate();
        void PrintTime(const double vector_time, const double list_time);
 
        void PrintVector(std::vector<int> v, std::string str);
        void DichotomieSearchVector(std::vector<int>& vector, const int value, std::vector<int>::iterator it, int coef);
        std::vector<int> SortVector(std::vector<int> vector);

        void PrintList(std::list<int> l, std::string str);
        void DichotomieSearchList(std::list<int>& list, const int value, std::list<int>::iterator it, int coef);
        std::list<int> SortList(std::list<int> list);

    public :
        PmergeMe();
        PmergeMe(const PmergeMe& cpy);
        PmergeMe& operator=(const PmergeMe& cpy);
        ~PmergeMe();

        void Sort(char **arg);

        class PmergeMeException : std::exception
        {
            public :
                virtual const char* what() const throw() { return ""; }
        };

        class FindDichotomie : std::exception
        {
            public :
                virtual const char* what() const throw() { return ""; }
        };
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:42:10 by picatrai          #+#    #+#             */
/*   Updated: 2024/05/04 09:20:33 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
    *this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy)
{
    this->_vector = cpy._vector;
    this->_list = cpy._list;
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::IsOnly(const std::string str, const std::string charset)
{
    bool find;

    for(size_t i = 0; i < str.size(); i++)
    {
        find = false;
        for (size_t j = 0; j < charset.size(); j++)
        {
            if (str[i] == charset[j])
                find = true;
        }
        if (find == false)
            return (false);
    }
    return (true);
}

void PmergeMe::IsDuplicate()
{
    std::vector<int> cpy(this->_vector);
    std::sort(cpy.begin(), cpy.end());
    for (std::vector<int>::iterator it = cpy.begin(); it != (cpy.end() - 1); it++)
    {
        if (*it == *(it + 1))
        {
            std::cout << RED << "Error: duplicate numbers" << RESET << std::endl;
            throw PmergeMe::PmergeMeException();
        }
    }
}

void PmergeMe::GetData(char **arg)
{
    this->_vector.clear();
    this->_list.clear();
    while (*arg)
    {
        std::string input (*arg);
        if (this->IsOnly(*arg, "0123456789 ") == false)
        {
            std::cout << RED << "Error: Unknown caracter" << RESET << std::endl;
            throw PmergeMe::PmergeMeException();
        }
        if (this->IsOnly(*arg, " ") == true)
        {
            std::cout << RED << "Error: an arg is empty" << RESET << std::endl;
            throw PmergeMe::PmergeMeException();
        }

        for (size_t index = 0; (*arg)[index]; index++)
        {
            std::string mini;
            while ((*arg)[index] == ' ')
                index++;
            size_t lim = input.find(' ', index);
            if (lim == std::string::npos)
            {
                mini = input.substr(index, input.size() - index);
                index = input.size() - 1;
            }
            else
            {
                mini = input.substr(index, lim - index);
                index = lim - 1;
            }
            if (mini != "")
            {
                long long val = std::atoll(mini.c_str());
                if (val > 2147483647 || val < -2147483648)
                {
                    std::cout << RED << "Error: a number can't fit into an int" << RESET << std::endl;
                    throw PmergeMe::PmergeMeException();
                }
                this->_vector.push_back(static_cast<int>(val));
                this->_list.push_back(static_cast<int>(val));
            }
        }
        arg++;
    }
    this->IsDuplicate();
}

void PmergeMe::PrintTime(const double vector_time, const double list_time)
{
    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector<int> : " << std::fixed << std::setprecision(5) << vector_time << " us" << std::endl;
    std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list<int>   : " << std::fixed << std::setprecision(5) << list_time << " us" << std::endl;
}










void PmergeMe::PrintVector(std::vector<int> v, std::string str)
{
    std::cout << str << "   ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::DichotomieSearchVector(std::vector<int>& vector, const int value, std::vector<int>::iterator it, int coef)
{
    if (vector.size() == 1)
    {
        if (*it > value)
        {
            vector.insert(it, value);
            throw FindDichotomie();
        }
        else
        {
            it = vector.end();
            vector.insert(it, value);
            throw FindDichotomie();
        }
    }
    if (*it > value && *(it - 1) > value)
    {
        coef *= 2;
        if (vector.size() / coef == 0 && it == vector.begin())
        {
            vector.insert(vector.begin(), value);
            throw FindDichotomie();
        }
        else if (vector.size() / coef == 0)
        {
            it--;
        }
        else
            it -= vector.size() / coef;
        this->DichotomieSearchVector(vector, value, it, coef);
    }
    else if (*it < value && *(it - 1) < value)
    {
        coef *= 2;
        if (vector.size() / coef == 0 && it == vector.end() - 1)
        {
            vector.insert(vector.end(), value);
            throw FindDichotomie();
        }
        else if (vector.size() / coef == 0)
        {
            it++;
        }
        else
            it += vector.size() / coef;
        this->DichotomieSearchVector(vector, value, it, coef);
    }
    vector.insert(it, value);
    throw FindDichotomie();
}

std::vector<int> PmergeMe::SortVector(std::vector<int> v)
{
    int odd = -1;
    if (v.size() % 2 == 1)
        odd = *(v.end() - 1);
    std::vector<int> high;
    std::vector<int> low;
    int nb_pair = v.size() / 2;
    std::vector<int>::iterator it = v.begin();
    while (--nb_pair >= 0)
    {
        if (*it > *(it + 1))
        {
            high.push_back(*it);
            low.push_back(*(it + 1));
        }
        else
        {
            high.push_back(*(it + 1));
            low.push_back(*it);
        }
        it += 2;
    }
    std::vector<int> main;
    if (high.size() > 1)
        main = this->SortVector(high);
    else
        main = high;
    std::vector<int>::iterator it2 = main.begin();
    it2 += main.size() / 2;
    while (low.size())
    {
        it2 = main.begin();
        it2 += main.size() / 2;
        try
        {
            this->DichotomieSearchVector(main, *(low.begin()), it2, 2);
            
        }
        catch(PmergeMe::FindDichotomie& e) {}
        low.erase(low.begin());
    }
    it2 = main.begin();
    it2 += main.size() / 2;
    try
    {
        if (odd != -1)
            this->DichotomieSearchVector(main, odd, it2, 2);
    }
    catch(PmergeMe::FindDichotomie& e) {}
    return (main);
}








std::list<int>::iterator operator+=(std::list<int>::iterator& it, std::size_t n)
{
    std::advance(it, n);
    return (it);
}

std::list<int>::iterator operator-=(std::list<int>::iterator& it, std::size_t n)
{
    std::advance(it, -n);
    return (it);
}

std::list<int>::iterator operator+(std::list<int>::iterator it, std::size_t n)
{
    std::list<int>::iterator it2(it);
    std::advance(it2, n);
    return (it2);
}

std::list<int>::iterator operator-(std::list<int>::iterator it, std::size_t n)
{
    std::list<int>::iterator it2(it);
    std::advance(it2, -n);
    return (it2);
}



void PmergeMe::PrintList(std::list<int> l, std::string str)
{
    std::cout << str << "   ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::DichotomieSearchList(std::list<int>& list, const int value, std::list<int>::iterator it, int coef)
{
    if (list.size() == 1)
    {
        if (*it > value)
        {
            list.insert(it, value);
            throw FindDichotomie();
        }
        else
        {
            it = list.end();
            list.insert(it, value);
            throw FindDichotomie();
        }
    }
    if (*it > value && *(it - 1) > value)
    {
        coef *= 2;
        if (list.size() / coef == 0 && it == list.begin())
        {
            list.insert(list.begin(), value);
            throw FindDichotomie();
        }
        else if (list.size() / coef == 0)
        {
            it--;
        }
        else
            it -= list.size() / coef;
        this->DichotomieSearchList(list, value, it, coef);
    }
    else if (*it < value && *(it - 1) < value)
    {
        coef *= 2;
        if (list.size() / coef == 0 && it == list.end() - 1)
        {
            list.insert(list.end(), value);
            throw FindDichotomie();
        }
        else if (list.size() / coef == 0)
        {
            it++;
        }
        else
            it += list.size() / coef;
        this->DichotomieSearchList(list, value, it, coef);
    }
    list.insert(it, value);
    throw FindDichotomie();
}

std::list<int> PmergeMe::SortList(std::list<int> l)
{
    int odd = -1;
    if (l.size() % 2 == 1)
        odd = *(l.end() - 1);
    std::list<int> high;
    std::list<int> low;
    int nb_pair = l.size() / 2;
    std::list<int>::iterator it = l.begin();
    while (--nb_pair >= 0)
    {
        if (*it > *(it + 1))
        {
            high.push_back(*it);
            low.push_back(*(it + 1));
        }
        else
        {
            high.push_back(*(it + 1));
            low.push_back(*it);
        }
        it += 2;
    }
    std::list<int> main;
    if (high.size() > 1)
        main = this->SortList(high);
    else
        main = high;
    std::list<int>::iterator it2 = main.begin();
    it2 += main.size() / 2;
    while (low.size())
    {
        it2 = main.begin();
        it2 += main.size() / 2;
        try
        {
            this->DichotomieSearchList(main, *(low.begin()), it2, 2);
            
        }
        catch(PmergeMe::FindDichotomie& e) {}
        low.erase(low.begin());
    }
    it2 = main.begin();
    it2 += main.size() / 2;
    try
    {
        if (odd != -1)
            this->DichotomieSearchList(main, odd, it2, 2);
    }
    catch(PmergeMe::FindDichotomie& e) {}
    return (main);
}




void PmergeMe::Sort(char **arg)
{
    try
    {
        std::clock_t start;
        this->GetData(arg);
        this->PrintVector(this->_vector, "Before:   ");
        // this->PrintList(this->_list, "Before:   ");
        
        
        start = std::clock();
        if (this->_vector.size() > 1)
            this->_vector = this->SortVector(this->_vector);
        double vector_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;


        start = std::clock();
        if (this->_list.size() > 1)
            this->_list = this->SortList(this->_list);
        double list_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;



        this->PrintVector(this->_vector, "After:    ");
        // this->PrintList(this->_list, "After:    ");
        this->PrintTime(vector_time, list_time);
    }
    catch (PmergeMe::PmergeMeException& e) {}
}
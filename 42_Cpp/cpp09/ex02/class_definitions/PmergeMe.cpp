#include "../class/PmergeMe.hpp"
#include <cstddef>
#include <list>
#include <vector>
#include <iostream>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        // Copy any other members if they exist
    }
    return *this;
}

void PmergeMe::insertionSortVector(std::vector<int>& arr)
{
    for (std::vector<int>::iterator it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        std::vector<int>::iterator it2 = it1;
        while (it2 != arr.begin() && *(it2 - 1) > temp)
        {
            *it2 = *(it2 - 1);
            --it2;
        }
        *it2 = temp;
    }
}

void PmergeMe::insertionSortList(std::list<int>& lst)
{
    if (lst.size() <= 1)
        return;

    std::list<int> temp;
    temp.splice(temp.end(), lst, lst.begin());

    for (std::list<int>::const_iterator it1 = lst.begin(), end = lst.end(); it1 != end; ++it1)
    {
        for (std::list<int>::iterator it2 = temp.begin();; ++it2)
        {
            if (it2 == temp.end() || *it1 < *it2)
            {
                temp.insert(it2, *it1);
                break;
            }
        }
    }

    lst.swap(temp);
}

std::list<int> PmergeMe::mergeInsertion(const std::list<int>& left, const std::list<int>& right)
{
    std::list<int> result;
    std::list<int>::const_iterator it_left = left.begin();
    std::list<int>::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left <= *it_right)
        {
            result.push_back(*it_left);
            ++it_left;
        }
        else
        {
            result.push_back(*it_right);
            ++it_right;
        }
    }

    result.insert(result.end(), it_left, left.end());
    result.insert(result.end(), it_right, right.end());

    return result;
}

std::list<int> PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return std::list<int>(arr.begin(), arr.end());

    size_t mid = arr.size() / 2;
    std::vector<int> left_part(arr.begin(), arr.begin() + mid);
    std::vector<int> right_part(arr.begin() + mid, arr.end());

    insertionSortVector(left_part);
    insertionSortVector(right_part);

    std::list<int> sorted_left(left_part.begin(), left_part.end());
    std::list<int> sorted_right(right_part.begin(), right_part.end());

    return mergeInsertion(sorted_left, sorted_right);
}

std::list<int> PmergeMe::fordJohnsonSortList(std::list<int>& lst)
{
    if (lst.size() <= 1)
        return lst;

    size_t mid = std::distance(lst.begin(), lst.end()) / 2;
    std::list<int>::iterator mid_it = lst.begin();
    std::advance(mid_it, mid);

    std::list<int> left_part(lst.begin(), mid_it);
    std::list<int> right_part(mid_it, lst.end());

    insertionSortList(left_part);
    insertionSortList(right_part);

    std::list<int> sorted_left(left_part.begin(), left_part.end());
    std::list<int> sorted_right(right_part.begin(), right_part.end());

    return mergeInsertion(sorted_left, sorted_right);
}

PmergeMe::~PmergeMe()
{
}


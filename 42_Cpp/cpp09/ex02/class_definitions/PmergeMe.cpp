// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

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

PmergeMe&    PmergeMe::operator = (const PmergeMe& other)
{
    if (this != &other)
    {

    }
    return (*this);
}

void    PmergeMe::insertionSortVector(std::vector<int>& array)
{
    for (std::vector<int>::iterator it1 = array.begin() + 1; it1 != array.end(); it1++)
    {
        int temp = *it1;
        std::vector<int>::iterator  it2 = it1;
        while (it2 != array.begin() && *(it2 - 1) > temp)
        {
            *it2 = *(it2 - 1);
            --it2;
        }
        *it2 = temp;
    }
}


std::list<int>  PmergeMe::mergeInsertion(const std::list<int>& arrOne, const std::list<int>& arrTwo)
{
    std::list<int>  result;
    std::list<int>::const_iterator    itOne = arrOne.begin();
    std::list<int>::const_iterator    itTwo = arrTwo.begin();

    while (itOne != arrOne.end() && itTwo != arrTwo.end())
    {
        if (*itOne <= *itTwo)
        {
            result.push_back(*itOne);
            ++itOne;
        }
        else
        {
            result.push_back(*itTwo);
            ++itTwo;
        }
    }

    result.insert(result.end(), itOne, arrOne.end());
    result.insert(result.end(), itTwo, arrTwo.end());

    return result;
}

std::list<int>  PmergeMe::fordJohnsonSortVector(std::vector<int>& array)
{
    if (array.size() <= 1)
        return std::list<int>(array.begin(), array.end());

    size_t  centerOfArray = array.size() / 2;
    std::vector<int>splitOne(array.begin(), array.begin() + centerOfArray);
    std::vector<int>splitTwo(array.begin() + centerOfArray, array.end());

    insertionSortVector(splitOne);
    insertionSortVector(splitTwo);

    std::list<int>sortedOne(splitOne.begin(), splitOne.end());
    std::list<int>sortedTwo(splitTwo.begin(), splitTwo.end());

    return mergeInsertion(sortedOne, sortedTwo);
}
        
void    PmergeMe::printList(const std::list<int>& list)
{
    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}


// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <vector>
#include <iostream>

class   PmergeMe
{
    public:
        PmergeMe();
 
        PmergeMe(const PmergeMe& other);

        PmergeMe&    operator = (const PmergeMe& other);

        std::list<int> fordJohnsonSortVector(std::vector<int>& array);
        std::list<int> fordJohnsonSortList(std::list<int>& lst);

        template <typename T>
        void    display(const T& container){
            for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        ~PmergeMe();
    private:
        void    insertionSortVector(std::vector<int>& array);
        void    insertionSortList(std::list<int>& lst);
        std::list<int> mergeInsertion(const std::list<int>& arrOne, const std::list<int>& arrTwo);
        
};

#endif


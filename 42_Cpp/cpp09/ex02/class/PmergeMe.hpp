// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <vector>
class   PmergeMe
{
    public:
        PmergeMe();
 
        PmergeMe(const PmergeMe& other);

        PmergeMe&    operator = (const PmergeMe& other);

        std::list<int> fordJohnsonSortVector(std::vector<int>& array);

        void    printList(const std::list<int>& list);

        ~PmergeMe();
    private:
        void    insertionSortVector(std::vector<int>& array);
        std::list<int> mergeInsertion(const std::list<int>& arrOne, const std::list<int>& arrTwo);
        
};

#endif


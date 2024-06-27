#include "./class/PmergeMe.hpp"
#include <list>

int     main(void)
{
    std::vector<int> array;
    array.push_back(5);
    array.push_back(3);
    array.push_back(8);
    array.push_back(4);
    array.push_back(2);
    array.push_back(7);
    array.push_back(1);
    array.push_back(6);
    
    PmergeMe    pmergeme;
    std::list<int> sorted_array = pmergeme.fordJohnsonSortVector(array);
    pmergeme.printList(sorted_array);
}

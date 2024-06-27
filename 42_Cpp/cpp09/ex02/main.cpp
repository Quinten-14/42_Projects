#include "./class/PmergeMe.hpp"
#include <iomanip>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::list<int> generateRandomList(int size) {
    std::list<int> random_list;
    
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < size; ++i) {
        random_list.push_back(rand() % 100000);
    }
    
    return random_list;
}

int     main(void)
{
    int size = 5000;

    PmergeMe    pmerge;
    std::list<int> list_container = generateRandomList(size);
    std::vector<int> vector_container(list_container.begin(), list_container.end());

    std::clock_t    startTimeList = std::clock();
    std::list<int>  sortedList = pmerge.fordJohnsonSortList(list_container);
    std::clock_t    endTimeList = std::clock();
    double  elapsedTimeList = static_cast<double>(endTimeList - startTimeList) / CLOCKS_PER_SEC;

    std::clock_t    startTimeVector = std::clock();
    std::list<int>  sortedVector = pmerge.fordJohnsonSortVector(vector_container);
    std::clock_t    endTimeVector = std::clock();
    double  elapsedTimeVector = static_cast<double>(endTimeVector - startTimeVector) / CLOCKS_PER_SEC;

    std::cout << "Unsorted: ";
    pmerge.display(list_container);
    std::cout << "\nSorted (First Container): ";
    pmerge.display(sortedList);
    std::cout << "\nTime used by first container: " << std::fixed << std::setprecision(8) << elapsedTimeList << " seconds\n";

    std::cout << "\nSorted (Second Container): ";
    pmerge.display(sortedVector);
    std::cout << "\nTime used by second container: " << std::fixed << std::setprecision(8) << elapsedTimeVector << " seconds\n";
}

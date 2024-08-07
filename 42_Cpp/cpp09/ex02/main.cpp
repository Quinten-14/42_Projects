#include "./class/PmergeMe.hpp"
#include <iomanip>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::list<int> takeInput(char **av)
{
    std::list<int> inputList;
    for (int i = 1; av[i] != NULL; ++i)
    {
        char *end;
        long value = strtol(av[i], &end, 10);

        if (value > 2147483647 || value < -2147483648)
        {
            std::cerr << "Invalid input: " << av[i] << " is not a valid integer." << std::endl;
            continue;
        }
        inputList.push_back(static_cast<int>(value));
    }
    return inputList;
}


int     main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Wrong amount of arguments" << std::endl;
        return 0;
    }

    PmergeMe    pmerge;
    std::list<int> list_container = takeInput(av);
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

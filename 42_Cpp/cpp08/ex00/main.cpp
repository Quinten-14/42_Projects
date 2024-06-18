#include "./templates/easyfind.hpp"
#include <exception>
#include <map>
#include <vector>
#include <iostream>

int     main(void)
{
    std::cout << "Vector Way" << std::endl;

    try
    {
        std::vector<int>    vector;
        for (int i = 0; i < 7; i++)
            vector.push_back(i);
        
        std::cout << "Found integer in vector: " << easyfind(vector, 6) - vector.begin() << std::endl;
        std::cout << "Found integer in vector: " << easyfind(vector, 10) - vector.begin() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nMap Way" << std::endl;

    try
    {
        std::map<int, int>  map;
        for (int i = 0; i < 7; i++)
            map[i] = i;

        std::cout << "Found integer in map: " << easyfind(map, 3)->first << " with value: " << easyfind(map, 3)->second << std::endl;
        std::cout << "Found integer in map: " << easyfind(map, 10)->first << " with value: " << easyfind(map, 10)->second << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

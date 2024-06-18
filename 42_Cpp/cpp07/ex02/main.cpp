#include "./class/Array.hpp"

int main()
{
    try
    {
        Array<int> arr1(5);
        for (unsigned int i = 0; i < arr1.size(); ++i)
        {
            arr1[i] = i + 1;
        }

        Array<int> arr2 = arr1;
        arr2[2] = 10;

        for (unsigned int i = 0; i < arr1.size(); ++i)
        {
            std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
        }

        for (unsigned int i = 0; i < arr2.size(); ++i)
        {
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    std::cout << "\nException testing" << std::endl;
    try
    {
        Array<int> arr(5);
        std::cout << "Trying to access index 10" << std::endl;
        std::cout << arr[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

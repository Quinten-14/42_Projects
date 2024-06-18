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

    std::cout << "\nDefault constructor test" << std::endl;
    Array<int>  arr3;


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

// MAin provided by 42

/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

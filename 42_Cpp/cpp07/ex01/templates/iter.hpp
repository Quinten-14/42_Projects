template <typename T>

void    iter(T* addrArray, int arrLength, void (*func)(T&))
{
    for (int i = 0; i < arrLength; i++)
        func(addrArray[i]);
}

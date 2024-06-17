template <typename T>
void    swap(T& a, T& b)
{
    T   temp;

    temp = b;
    b = a;
    a = temp;
}

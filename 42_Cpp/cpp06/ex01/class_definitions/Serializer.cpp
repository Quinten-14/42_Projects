#include "../Main.h"
#include <cstdint>

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

uintptr_t   Serializer::serialize(Data *ptrToData)
{
    return reinterpret_cast<uintptr_t>(ptrToData);
}

Data*       Serializer::deserialize(uintptr_t serializedAddress)
{
    return reinterpret_cast<Data*>(serializedAddress);
}

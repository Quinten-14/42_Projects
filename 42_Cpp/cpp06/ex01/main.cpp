#include "./Main.h"
#include "class/Serializer.hpp"
#include <cstdint>
#include <iostream>


int main(void)
{
    Data *data1 = new Data;
    data1->favo_boardgame = "Scyth";

    Data *data2 = new Data;
    data2->favo_boardgame = "Catan";

    uintptr_t serializedAddress1 = Serializer::serialize(data1);
    uintptr_t serializedAddress2 = Serializer::serialize(data2);

    Data *serializedData1 = Serializer::deserialize(serializedAddress1);
    Data *serializedData2 = Serializer::deserialize(serializedAddress2);

    std::cout << "Original data1: " << data1->favo_boardgame << std::endl;
    std::cout << "Deserialized data1: " << serializedData1->favo_boardgame << std::endl;

    std::cout << "Original data2: " << data2->favo_boardgame << std::endl;
    std::cout << "Deserialized data2: " << serializedData2->favo_boardgame << std::endl;

    delete data1;
    delete data2;

    Data *nullData = nullptr;

    uintptr_t serializedNull = Serializer::serialize(nullData);

    Data *deserializedNull = Serializer::deserialize(serializedNull);

    if (deserializedNull == nullptr)
        std::cout << "Successfully handled null pointer." << std::endl;
    else
        std::cout << "The value of the nullptr is not right." << std::endl;

    return 0;
}

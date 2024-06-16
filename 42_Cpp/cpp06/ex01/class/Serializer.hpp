#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class   Serializer
{
    public:
        static uintptr_t    serialize(Data* ptrToData);
        static Data*        deserialize(uintptr_t serializedAddress);

    private:
        // Needed for canonical form that subject asks
        Serializer(void);
        Serializer(const Serializer &other);
        Serializer& operator = (const Serializer &other);
        ~Serializer(void);
};

#endif

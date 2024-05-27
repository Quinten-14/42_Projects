#ifndef DOG_HPP
# define DOG_HPP

class   Dog : public Animal
{
    public:
        // Constructor
        Dog(void);

        // Copy Constructor
        Dog(const Dog& other);

        // Copy Assignment
        Dog& operator = (const Dog& other);

        // Woefer
        void makeSound(void) const;

        // Destructor
        ~Dog(void);
};

#endif

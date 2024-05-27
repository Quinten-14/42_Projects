#ifndef CAT_HPP
# define CAT_HPP

class   Cat : public Animal
{
    public:
        // Constructor
        Cat(void);

        // Copy Constructor
        Cat(const Cat& other);

        // Copy Assignment
        Cat& operator = (const Cat& other);

        // Meower
        void makeSound(void) const;

        // Destructor
        ~Cat(void);
};

#endif

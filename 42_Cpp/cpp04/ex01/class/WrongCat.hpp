#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class   WrongCat : public WrongAnimal
{
    public:
        // Constructor
        WrongCat(void);

        // Copy Constructor
        WrongCat(const WrongCat& other);

        // Copy Assignment
        WrongCat& operator = (const WrongCat& other);

        // Meower
        void makeSound(void) const;

        // Destructor
        ~WrongCat(void);
};

#endif

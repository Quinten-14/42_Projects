#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class   Animal
{
    public:
        // Constructor
        Animal(void);

        // Copy Constructor
        Animal(const Animal& other);

        // Copy Assignment
        Animal& operator = (const Animal& other);

        // Type Getter
        virtual std::string getType(void) const;

        // Animal Sound
        virtual void makeSound(void) const;

        // Destructor
        virtual ~Animal(void);

    protected:
        std::string type;
};

#endif

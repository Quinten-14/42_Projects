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

        // Setter
        void    setIdea(std::string, int i);

        // Getters
        std::string getIdea(int i) const;
        Brain* getBrainAddress(void) const;

        // Destructor
        ~Dog(void);

    private:
        Brain* m_brain;
};

#endif

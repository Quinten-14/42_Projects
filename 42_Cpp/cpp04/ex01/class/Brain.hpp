#ifndef BRAIN_HPP
# define BRAIN_HPP

class   Brain
{
    public:
        // Constructor
        Brain(void);

        // Copy Constructor
        Brain(const Brain& other);

        // Copy Assignment
        Brain& operator = (const Brain& other);

        // Setter
        void    ideaSetter(std::string idea, int i);

        // Getter
        const std::string*    ideaGetter(int i);

        // Destructor
        ~Brain(void);

    private:
        std::string m_ideas[100];
};

#endif

// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class   MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator    iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator    reverse_iterator;

        MutantStack() : std::stack<T>() {}
 
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}

        MutantStack&    operator = (const MutantStack& other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return (*this);
        }

        iterator begin(void) {
            return (std::stack<T>::c.begin());
        }

        iterator end(void) {
            return (std::stack<T>::c.end());
        }

        reverse_iterator rbegin(void) {
            return (std::stack<T>::c.rbegin());
        }

        reverse_iterator rend(void) {
            return (std::stack<T>::c.rend());
        }

        virtual ~MutantStack() {}

    private:
        
};

#endif


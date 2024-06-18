#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>

class   Array
{
    public:
        Array(void) :  m_array(NULL), m_size(0) { this->m_array = new T[this->m_size]; std::cout << "Empty array created. Size 0" << std::endl; }

        Array(unsigned int n) : m_size(n) { this->m_array = new T[this->m_size]; std::cout << "Array created with size: " << this->m_size << std::endl; }

        Array(const Array& other) : m_array(NULL), m_size(0) { *this = other; std::cout << "Copy constructor called" << std::endl; }

        Array&  operator=(const Array& other) {
            if (this != &other)
            {
                delete[] m_array;
                m_size = other.m_size;
                if (m_size > 0)
                {
                    m_array = new T[m_size];
                    for (unsigned int i = 0; i < m_size; ++i)
                        m_array[i] = other.m_array[i];
                }
                else
                    m_array = NULL;
            }
            return *this;
        }

        T& operator[](unsigned int index) {
            if (index >= m_size)
                throw InvalidIndexException();
            return m_array[index];
        }

        unsigned int    size() const { return m_size; }

        class   InvalidIndexException : public std::exception {
            virtual const char* what() const throw() { return "Error: Invalid index";}
        };

        ~Array() { delete[] this->m_array; }

    private:
        T       *m_array;
        int     m_size;
};

#endif

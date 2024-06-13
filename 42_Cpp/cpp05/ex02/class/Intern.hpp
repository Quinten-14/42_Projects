#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
    public:
        // Constructor
        Intern();

        // Copy Constructor
        Intern(const Intern& other);

        // Copy Assignment
        Intern& operator=(const Intern& other);

        // Destructor
        ~Intern();

        Form* makeForm(const std::string& formName, const std::string& target) const;

    private:
};

#endif

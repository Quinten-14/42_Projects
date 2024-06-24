// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
class   RPN
{
    public:
        RPN();
 
        RPN(const RPN& other);

        RPN&    operator = (const RPN& other);

        ~RPN();
    private:
        std::stack<double>  value_stack;
};

#endif


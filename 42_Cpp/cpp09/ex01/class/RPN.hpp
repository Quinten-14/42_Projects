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

        double  caculateResultRPN(const std::string inputStr);

        ~RPN();
    private:
        std::stack<double>  m_valueStack;
};

#endif


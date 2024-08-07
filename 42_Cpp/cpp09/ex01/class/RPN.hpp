// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class   RPN
{
    public:
        RPN();
 
        RPN(const RPN& other);

        RPN&    operator = (const RPN& other);

        double  caculateResultRPN(const std::string inputStr);

        class   ErrorException : public std::exception {
            virtual const char* what() const throw();
        };

        ~RPN();
    private:
        std::stack<double>  m_valueStack;

    private:
        void    doCalculationOperator(const std::string token, double operand1, double operand2);
};

#endif


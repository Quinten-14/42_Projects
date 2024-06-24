// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#include "../class/RPN.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN&    RPN::operator = (const RPN& other)
{
    if (this != &other)
    {

    }
    return (*this);
}

double  RPN::caculateResultRPN(const std::string inputStr)
{
    std::istringstream  tokens(inputStr);
    std::string         token;

    while (tokens >> token)
    {
        if (isdigit(token[0]))
            m_valueStack.push(std::stod(token));
        else if (token == "(" || token == ")")
            throw std::runtime_error("Invalid RPN: parentheses found");
        else
        {
            if (m_valueStack.size() < 2)
                throw std::runtime_error("Invalid RPN: not enough operands");
            double  operand2 = m_valueStack.top();
            m_valueStack.pop();
            double  operand1 = m_valueStack.top();
            m_valueStack.pop();

            if (token == "+")
                m_valueStack.push(operand1 + operand2);
            else if (token == "-")
                m_valueStack.push(operand1 - operand2);
            else if (token == "*")
                m_valueStack.push(operand1 * operand2);
            else if (token == "/")
                m_valueStack.push(operand1 / operand2);
            else
                throw std::runtime_error("Unknown operator: " + token);
        }
    }

    if (m_valueStack.size() != 1)
        throw std::runtime_error("Invalid RPN found");

    return m_valueStack.top();
}

RPN::~RPN()
{

}


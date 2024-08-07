// Made by Quinten Raymaekers
// Contact at raymaekersq@gmail.com

#include "../class/RPN.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>

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
        this->m_valueStack = other.m_valueStack;
    return (*this);
}

const char* RPN::ErrorException::what() const throw()
{
    return "Error";
}

void    RPN::doCalculationOperator(const std::string token, double operand1, double operand2)
{
    if (token == "+")
        m_valueStack.push(operand1 + operand2);
    else if (token == "-")
        m_valueStack.push(operand1 - operand2);
    else if (token == "*")
        m_valueStack.push(operand1 * operand2);
    else if (token == "/")
    {
        if (operand2 == 0)
            throw std::domain_error("Division by zero");
        m_valueStack.push(operand1 / operand2);
    }
    else
        throw ErrorException();
}

double RPN::caculateResultRPN(const std::string inputStr)
{
    std::istringstream tokens(inputStr);
    std::string token;

    while (tokens >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
        {
            char* end;
            double value = std::strtod(token.c_str(), &end);
            if (*end != '\0')
                throw ErrorException();
            m_valueStack.push(value);
        }
        else
        {
            if (m_valueStack.size() < 2)
                throw ErrorException();
            double operand2 = m_valueStack.top();
            m_valueStack.pop();
            double operand1 = m_valueStack.top();
            m_valueStack.pop();

            doCalculationOperator(token, operand1, operand2);
        }
    }

    if (m_valueStack.size() != 1)
        throw ErrorException();

    return m_valueStack.top();
}

RPN::~RPN()
{

}


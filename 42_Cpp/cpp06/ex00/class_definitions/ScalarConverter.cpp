#include "../main.h"
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other) {}
    return *this;
}

static bool hasDot(const std::string& input)
{
    return (input.find('.') != std::string::npos);
}

static bool hasFloatSign(const std::string& input)
{
    return (input.find('f') != std::string::npos);
}

static bool isSpecialCase(const std::string& input)
{
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
        return true;
    return false;
}

static bool isChar(const std::string& input)
{
    size_t  input_length = input.length();

    if (input_length == 1 && !isdigit(input[0]))
        return true;
    else if (input_length == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    return false;
}

static bool isInt(const std::string& input)
{
    try
    {
        size_t pos;
        int value = std::stoi(input, &pos);

        return pos == input.length() && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
    }
    catch (...)
    {
        return false;
    }
}

e_type ScalarConverter::typeIdentifier(const std::string& input)
{
    if (hasDot(input))
    {
        if (hasFloatSign(input))
            return FLOAT;
        else
            return DOUBLE;
    }
    else
    {
        if (isSpecialCase(input))
            return PSEUDO;
        if (isChar(input))
            return CHAR;
        if (isInt(input))
            return INT;
    }
    return INVALID;
}

void    ScalarConverter::convert(const std::string& input)
{
    e_type  type;

    type = typeIdentifier(input);
    std::cout << type << std::endl;
}

ScalarConverter::~ScalarConverter() {}

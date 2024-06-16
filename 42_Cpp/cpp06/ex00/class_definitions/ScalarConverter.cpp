#include "../main.h"
#include <cctype>
#include <limits>
#include <locale>

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

void    ConvertFromPseudo(const std::string& input)
{
    if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

template<typename T>
bool    isPrintable(T value)
{
    if (!isprint(value))
        std::cout << "char: Non displayable" << std::endl;
    else
        return (false);
    return (true);
}

void    ConvertFromChar(const std::string& input)
{
    char    character;

    if (input.length() == 1)
        character = input[0];
    else
        character = input[1];


    if (!isPrintable(character))
        std::cout << "char: " << character << std::endl;

    std::cout << "int: " << static_cast<int>(character) << std::endl;
    std::cout << "float: " << static_cast<float>(character) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(character) << ".0" << std::endl;
}

void    ConvertFromInt(const std::string& input)
{
    int value_integer = std::atoi(input.c_str());

    if (value_integer < 0 || value_integer > 127)
        std::cout << "char: impossible" << std::endl;
    else
        if (!isPrintable(value_integer))
            std::cout << "char: '" << static_cast<char>(value_integer) << "'" << std::endl;

    std::cout << "int: " << value_integer << std::endl;
    std::cout << "float: " << static_cast<float>(value_integer) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value_integer) << ".0" << std::endl;
}

bool    hasFractional(double value)
{
    return std::floor(value) != value;
}

void    ConvertFromFloatOrDouble(const std::string& input)
{
    float value_float = std::atof(input.c_str());

    if (value_float < 0 || value_float > 127)
        std::cout << "char: impossible" << std::endl;
    else
        if (!isPrintable(value_float))
            std::cout << "char: '" << static_cast<char>(value_float) << "'" << std::endl;

    if (value_float < std::numeric_limits<int>::min() || value_float > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value_float) << std::endl;

    if (hasFractional(value_float))
    {
        std::cout << "float: " << value_float << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value_float) << std::endl;
    }
    else
    {
        std::cout << "float: " << value_float << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value_float) << ".0" << std::endl;
    }
}

void    ScalarConverter::convert(const std::string& input)
{
    e_type  type;

    type = typeIdentifier(input);

    if (type == PSEUDO)
        ConvertFromPseudo(input);
    else if (type == CHAR)
        ConvertFromChar(input);
    else if (type == INT)
        ConvertFromInt(input);
    else if (type == FLOAT || type == DOUBLE)
        ConvertFromFloatOrDouble(input);
    else if (type == INVALID)
        std::cout << "Invalid Input Type" << std::endl;
}

ScalarConverter::~ScalarConverter() {}

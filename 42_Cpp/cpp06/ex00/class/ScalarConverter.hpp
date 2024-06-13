#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

enum    e_type
{
    INVALID = -1,
    PSEUDO = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4
};

class   ScalarConverter
{
    public:
        static void convert(const std::string& input);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator = (const ScalarConverter& other);
        ~ScalarConverter();

    private:
        static e_type typeIdentifier(const std::string& input);
};

#endif

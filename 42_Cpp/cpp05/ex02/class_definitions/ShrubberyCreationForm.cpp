#include "../main.h"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {}
    return *this;
}

void ShrubberyCreationForm::executeConcrete() const
{
    std::fstream filestream;

    filestream.open(this->getTarget() + "_shrubbery", std::fstream::out | std::fstream::trunc);

    if (!filestream.good())
        std::cerr << "Error while opening target file" << std::endl;

    filestream <<
    "       _-_\n"
    "    /~~   ~~\\\n"
    " /~~         ~~\\\n"
    "{               }\n"
    " \\  _-     -_  /\n"
    "   ~  \\\\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\\\n";

    filestream.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

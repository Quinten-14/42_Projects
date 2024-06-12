#include "../main.h"

ShrubberyCreationForm::ShrubberyCreationForm(): Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): Form("ShrubberyCreationForm", target, 145, 137) {}

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
    std::fstream fs;

    fs.open(this->m_target + "_shrubbery", std::fstream::out | std::fstream::trunc);

    if (!fs.good())
        std::cerr << "Error while opening target file" << std::endl;

    fs << "Test";

    fs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

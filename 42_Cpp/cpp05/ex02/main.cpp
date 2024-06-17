#include "./main.h"

int main() {
    Bureaucrat jeffrey("Jeffrey", 1);

    try
    {
        ShrubberyCreationForm   shrubbery("home");
        jeffrey.signForm(shrubbery);
        jeffrey.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

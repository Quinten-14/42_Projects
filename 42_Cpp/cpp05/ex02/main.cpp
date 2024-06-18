#include "./main.h"

int main() {
    Bureaucrat jeffrey("Jeffrey", 1);

    try
    {
        PresidentialPardonForm   main_form("home");
        jeffrey.signForm(main_form);
        jeffrey.executeForm(main_form);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

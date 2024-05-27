#include "../phonebook_main.hpp"

PhoneBook::PhoneBook(void)
{
    current_index = 0;
}

void    PhoneBook::add_contact(const Contact contact)
{
    if (current_index < 0 || current_index > 7)
        current_index = 0;
    contacts[current_index] = contact;
    current_index++;
}

bool    PhoneBook::any_contacts(void) const
{
    for (int i = 0; i < 8; i++)
    {
        if (contacts[i].exists(i))
            return (true);
    }
    return (false);
}

void    PhoneBook::print_contacts(void) const
{
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for (int i = 0; i < 8; i++)
        contacts[i].view(i);
    std::cout << "---------------------------------------------" << std::endl;
}

void    PhoneBook::search(void) const
{
    int i = -1;
    bool    correct_input = false;

    while (correct_input == false)
    {
        std::cout << "Please enter index of the contact: " << std::flush;
        std::cin >> i;
        if (std::cin.eof())
        {
            std::cout << "\nExiting\n";
            std::exit(EXIT_SUCCESS);
        }
        if (i >= 0 && i <= 8 && std::cin.good())
            correct_input = true;
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Try Again" << std::endl;
        }
    }

    contacts[i].display(i);
}

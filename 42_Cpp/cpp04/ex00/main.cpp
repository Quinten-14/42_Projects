#include "./main.h"

int main(void)
{
    std::cout << "\n<--- Constructors --->\n" << std::endl;

    const Animal*   meta = new Animal();
    const Animal*   j = new Dog();
    const Animal*   i = new Cat();
    const WrongAnimal* k = new WrongCat();

    std::cout << "\n<--- Type Getters --->\n" << std::endl;
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    
    std::cout << "\n<--- Sound Makers --->\n" << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    k->makeSound();

    std::cout << "\n<--- Destructors --->\n" << std::endl;
    
    delete meta;
    delete j;
    delete i;
    delete k;

    std::cout << "\n<--- Extra Tests --->\n" << std::endl;

    const Animal*   meta_2 = new Dog();

    std::cout << meta_2->getType() << " " << std::endl;
    meta_2->makeSound();
    delete meta_2;

    const WrongAnimal*   meta_3 = new WrongCat();

    std::cout << meta_3->getType() << " " << std::endl;
    meta_3->makeSound();
    delete meta_3;
}

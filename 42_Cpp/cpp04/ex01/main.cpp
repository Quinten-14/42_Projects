#include "./main.h"

// Testing
int main(void)
{
    std::cout << "Constructors" << std::endl;
    const Animal* animals[2];

    animals[0] = new Cat();
    animals[1] = new Dog();

    std::cout << "\nFunctions" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Animal type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
        std::cout << std::endl;
    }

    std::cout << "\nDestructor" << std::endl;
    for (int i = 0; i < 2; i++)
        delete(animals[i]);

    std::cout << "\nDeep Copy tests" << std::endl;
    Dog* dog = new Dog();

    std::cout << "\nSet Brain Dog" << std::endl;
    dog->setIdea("Where is the ball", 0);
    dog->setIdea("Should I catch the stick", 1);

    std::cout << "\nCopy the Dog" << std::endl;
    Dog* dog_copy = new Dog(*dog);

    std::cout << "\nError Handling" << std::endl;
    dog->setIdea("Error Testing", 101);

    std::cout << "\nGet brain address and thoughts" << std::endl;
    std::cout << dog->getBrainAddress() << ": " << dog->getIdea(0) << std::endl;
    std::cout << dog->getBrainAddress() << ": " << dog->getIdea(1) << std::endl;

    
    std::cout << "\nError Handling" << std::endl;
    dog->getIdea(101);

    std::cout << "\nDestructor" << std::endl;
    delete(dog);


    std::cout << "\nGet brain address and thoughts (deep copy)" << std::endl;
    std::cout << dog_copy->getBrainAddress() << ": " << dog_copy->getIdea(0) << std::endl;
    std::cout << dog_copy->getBrainAddress() << ": " << dog_copy->getIdea(1) << std::endl;

    std::cout << "\nError Handling (deep copy)" << std::endl;
    dog_copy->getIdea(101);

    std::cout << "\nDestructor (deep copy)" << std::endl;
    delete(dog_copy);
}

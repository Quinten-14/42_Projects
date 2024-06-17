#include "./main.h"

Base    *generate(void)
{
    srand(time(NULL));
    int randomSeed = rand() % 3;

    //std::cout << randomSeed << std::endl;
    if (randomSeed == 0)
        return new A();
    else if (randomSeed == 1)
        return new B();
    else
        return new C();
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
    }
    catch (std::exception&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "Type B" << std::endl;
        }
        catch (std::exception)
        {
            C& c = dynamic_cast<C&>(p);
            std::cout << "Type C" << std::endl;
        }
    }
}

int     main(void)
{
    Base    *baseClass;
    baseClass = generate();

    identify(baseClass);
    identify(*baseClass);
}

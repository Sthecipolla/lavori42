#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(Brain const &value)
{
    int i;

    i = 0;
    std::cout << "Brain copy constructor" << std::endl;
    while (i < 100)
    {
        this->ideas[i] = value.ideas[i];
        i++;
    }
}

Brain &Brain::operator=(const Brain &value)
{
    int i;

    i = 0;
    std::cout << "Brain copy operator" << std::endl;
    if (this != &value)
    {
        while (i < 100)
        {
            this->ideas[i] = value.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}
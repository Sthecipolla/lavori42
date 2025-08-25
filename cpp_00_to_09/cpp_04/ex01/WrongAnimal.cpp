#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "wrongAnimal constructor called " << std::endl;
    this->type = "wrong animal";
}

void WrongAnimal::makeSound() const
{
    std::cout << "wrongAnimal sound " << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "wrongAnimal Copy constructor called " << std::endl;

    this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "wrongAnimal Copy assignment operator called " << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "wrongAnimald destructor called " << std::endl;
}

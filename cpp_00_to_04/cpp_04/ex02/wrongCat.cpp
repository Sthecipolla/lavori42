#include "wrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "wrong Cat";
}

WrongCat::WrongCat(WrongCat const &value) : WrongAnimal(value)
{
    std::cout << "wrongCat Copy constructor called " << std::endl;
    this->type = value.type;
}

WrongCat &WrongCat::operator=(WrongCat const &value)
{
    std::cout << "wrongCat Copy operator called " << std::endl;
    if (this != &value)
    {
        this->type = value.type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "wrongCat miaaaaaoooo " << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}

WrongCat::~WrongCat()
{
    std::cout << "destructor" << std::endl;
}

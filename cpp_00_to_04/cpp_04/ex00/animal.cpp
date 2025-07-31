#include "animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor" << std::endl;
	this->type = "none";
}

Animal::Animal(const Animal &value)
{
	std::cout << "Animal Copy custroctor called " << std::endl;
	this->type = value.type;
}

Animal& Animal::operator=(const Animal &value)
{
	std::cout << "Animal Copy assignment operator called " << std::endl;
	if (this != &value)
	{
		this->type = value.type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal soud" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

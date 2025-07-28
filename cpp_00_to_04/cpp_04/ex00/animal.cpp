#include "animal.hpp"

Animal::Animal()
{
	this->type = "none";
}

Animal::Animal(const Animal &value)
{
	std::cout << " Copy custroctor called " << std::endl;
	this->type = value.type;
}

Animal& Animal::operator=(const Animal &value)
{
	std::cout << " Copy assignment operator called " << std::endl;
	if (this != &value)
	{
		this->type = value.type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "no soud" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

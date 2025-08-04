#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &value) : Animal(value)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(Dog const &value)
{
	std::cout << "Dog Copy assignment operator called " << std::endl;
	if (this != &value)
	{
		this->type = value.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Baaaauuuuuuuuuuuu" << std::endl ; 
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
	// delete this;
}


#include "cat.hpp"


Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	this->type = "cat";
}

Cat::Cat(Cat const &value) : Animal(value)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->type = value.type;
}

Cat& Cat::operator=(Cat const &value)
{
	std::cout << "Cat Copy assignment operator called " << std::endl;
	if (this != &value)
	{
		this->type = value.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaaaaaaooooooo" << std::endl ; 
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	// delete this;
}

std::string Cat::getType() const
{
	return (this->type);
}

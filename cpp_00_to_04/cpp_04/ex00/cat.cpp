#include "cat.hpp"


Cat::Cat()
{
	this->type = "cat";
}

Cat::Cat(Cat const &value) : Animal(value)
{
	std::cout << "copy constructor" << std::endl;
	this->type = value.type;
}

Cat& Cat::operator=(Cat const &value)
{
	std::cout << "Copy assignment operator called " << std::endl;
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
	std::cout << "Destructor" << std::endl;
	// delete this;
}

std::string Cat::getType() const
{
	return (this->type);
}

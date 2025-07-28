#include "dog.hpp"

Dog::Dog()
{
	this->type = "dog";
}

Dog::Dog(Dog const &value)
{
	std::cout << "copy constructor" << std::endl;
	this->type = value.type;
}

Dog& Dog::operator=(Dog const &value)
{
	std::cout << "Copy assignment operator called " << std::endl;
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
	std::cout << "Destructor" << std::endl;

}

std::string Dog::getType() const
{
	return (this->type);
}

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(Dog const &value) : Animal(value)
{
	this->brain = new Brain(*value.brain);
	std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(Dog const &value)
{
	int i;

	i = 0;
	std::cout << "Dog Copy assignment operator called " << std::endl;
	if (this != &value)
	{
		while(i < 100)
		{
			this->brain[i] = value.brain[i];
			i ++;
		}
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
	delete this->brain;
}


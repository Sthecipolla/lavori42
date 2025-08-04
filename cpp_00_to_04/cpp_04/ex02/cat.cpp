#include "Cat.hpp"


Cat::Cat() : Animal()
{
	std::cout << "Cat constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(Cat const &value) : Animal(value)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->brain = new Brain(*value.brain);
}

Cat& Cat::operator=(Cat const &value) 
{
	int i;

	i = 0;
	std::cout << "Cat Copy assignment operator called " << std::endl;
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

void Cat::makeSound() const
{
	std::cout << "Miaaaaaaooooooo" << std::endl ; 
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	delete this->brain;
}

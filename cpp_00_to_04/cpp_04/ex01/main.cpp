#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"



int main()
{
	const int arraySize = 4;
	Animal *animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal " << i << " type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i];
	}

	std::cout << "------------------------------------ " << std::endl;

	Dog		dog;
	Animal *an = new Dog(dog);
	delete an;
	return 0;
}
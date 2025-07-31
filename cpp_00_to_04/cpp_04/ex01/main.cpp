#include "cat.hpp"
#include "dog.hpp"
#include "animal.hpp"



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

	return 0;
}
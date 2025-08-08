#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(Dog const &value);
	Dog &operator=(Dog const &value);
	~Dog();
	void makeSound() const;
};

#endif
#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"



class Dog : public Animal
{
	public :
		Dog();
		Dog(Dog const &value);
		Dog &operator=(Dog const &value);
		~Dog();
		void makeSound() const;

};

#endif
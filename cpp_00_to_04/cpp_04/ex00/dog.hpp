#ifndef DOG_H
#define DOG_H

#include "animal.hpp"



class Dog : public Animal
{
	public :
		Dog();
		Dog(Dog const &value);
		Dog &operator=(Dog const &value);
		~Dog();
		void makeSound() const;
		std::string getType() const;


};

#endif
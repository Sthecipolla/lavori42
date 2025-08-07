#ifndef ANIMAL_H
#define ANIMAL_H

#include "Share.hpp"

class Animal 
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(const Animal &value);
        Animal &operator=(const Animal &value);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif

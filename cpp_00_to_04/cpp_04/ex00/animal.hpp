#ifndef ANIMAL_H
#define ANIMAL_H

#include "share.hpp"

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
		virtual std::string getType() const;
};

#endif

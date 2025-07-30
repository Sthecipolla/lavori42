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
		virtual ~Animal() = 0;
		virtual void makeSound() const = 0;
		virtual std::string getType() const = 0;
/* 	public :
		Animal();
		Animal(Animal const &value);
		Animal &operator=(Animal const &value);
		~Animal(); */
	
};

#endif

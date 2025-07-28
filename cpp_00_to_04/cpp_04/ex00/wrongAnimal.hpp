#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "share.hpp"

class WrongAnimal
{
	protected :
		std::string type;
	public :
	 	WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
		WrongAnimal();
		virtual void makeSound() const;
		virtual std::string getType() const;
	
};


#endif
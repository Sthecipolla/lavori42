#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include "Share.hpp"

class WrongAnimal
{
	protected :
		std::string type;
	public :
	 	WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
		WrongAnimal();
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
	
};


#endif
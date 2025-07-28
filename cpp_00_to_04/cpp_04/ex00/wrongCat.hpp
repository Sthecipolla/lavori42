#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "wrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(WrongCat const &value);
		WrongCat &operator=(WrongCat const &value);
		~WrongCat();
		void makeSound() const;
		std::string getType() const;


};

#endif
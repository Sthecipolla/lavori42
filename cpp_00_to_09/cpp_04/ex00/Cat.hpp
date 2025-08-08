#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"



class Cat : public Animal
{
	public :
		Cat();
		Cat(Cat const &value);
		Cat &operator=(Cat const &value);
		~Cat();
		void makeSound() const;


};

#endif
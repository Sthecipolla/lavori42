#ifndef CAT_H
#define CAT_H

#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(Cat const &value);
	Cat &operator=(Cat const &value);
	~Cat();
	void makeSound() const;
	std::string getType() const;
};

#endif
#include "Zombie.hpp"

void Zombie::announce()
{
	if (this->name.compare("Foo") == 0)
	{
		std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
	}
	else
		std::cout << "<" << this->name << ">: " << "BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie: " << this->name << " died" << std::endl;
}

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::~Weapon()
{
	
}

const std::string &Weapon::getType()
{
	return (type);
}
void Weapon::setType(std::string type)
{
	this->type = type;
}
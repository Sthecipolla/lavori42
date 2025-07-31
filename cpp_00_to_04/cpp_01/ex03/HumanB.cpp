#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &we)
{
	this->weapon = &we;
}
Weapon HumanB::getWeapon()
{
	return (*this->weapon);
}
HumanB::~HumanB()
{
}

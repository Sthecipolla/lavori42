#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA( void )
{
	return ;
}
void HumanA::attack( void )
{
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}

Weapon HumanA::getWeapon( void )
{
	return (this->weapon);
}
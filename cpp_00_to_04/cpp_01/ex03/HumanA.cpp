#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
	
}
void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}

Weapon HumanA::getWeapon()
{
	return (this->weapon);
}
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(ClapTrap const &value)
{
}

ClapTrap &ClapTrap::operator=(ClapTrap const &value)
{
	//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
	{
		this->attackDamage = value.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string &target)
{
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
}

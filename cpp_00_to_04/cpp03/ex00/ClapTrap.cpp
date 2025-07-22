#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->attackDamage = 0;
	this->hitPoint = 10;
	this->energyPoints = 10;
	this->Name = "";
}

ClapTrap::ClapTrap(ClapTrap const &value)
{
	this->Name = value.Name;
	this->hitPoint = value.hitPoint;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &value)
{
	//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
	{
		this->Name = value.Name;
		this->hitPoint = value.hitPoint;
		this->energyPoints = value.energyPoints;
		this->attackDamage = value.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string &target)
{
	target.
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
}

// Getters
std::string ClapTrap::getName() const
{
	return this->Name;
}

int ClapTrap::getHitPoint() const
{
	return this->hitPoint;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

// Setters
void ClapTrap::setName(const std::string &name)
{
	this->Name = name;
}

void ClapTrap::setHitPoint(int hitPoint)
{
	this->hitPoint = hitPoint;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}


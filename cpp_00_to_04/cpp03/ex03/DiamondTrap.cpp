#include "DiamondTrap.hpp"

/* DiamondTrap::DiamondTrap()
{
} */

DiamondTrap::DiamondTrap(DiamondTrap const &value)
{
	this->Name = value.Name;
	this->hitPoint = value.hitPoint;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &value)
{
	std::cout << " Copy assignment operator called " << std::endl;
	if (this != &value)
	{
		this->Name = value.Name;
		this->hitPoint = value.hitPoint;
		this->energyPoints = value.energyPoints;
		this->attackDamage = value.attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->Name << " is being killed by YOU " << std::endl;
}

//------------------------------------------------------

DiamondTrap::DiamondTrap(std::string name)
{
	this->attackDamage = 0;
	this->hitPoint = 10;
	this->energyPoints = 10;
	this->Name = name;
	std::cout << "IS BOOOOOOOORN " << this->Name  << std::endl;
}


void DiamondTrap::attack(const std::string &target)
{
	if(this->energyPoints <= 0)
	{
		std::cout << this->Name << " is out of energy " << std::endl;
		return ;
	}
	else
		this->energyPoints--;
	std::cout << this->Name << " is attacking " << target << " and causing "<< this->attackDamage << " damage " << std::endl;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	
	this->hitPoint = this->hitPoint - amount;
	std::cout << this->Name << " is taking damage -" << amount << std::endl;	
	if(this->hitPoint < 0)
		this->hitPoint = 0;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;

}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if(this->hitPoint == 0)
	{
		std::cout << this->Name << " is dead cant be repared " << std::endl;
		return ;
	}
	if(this->energyPoints <= 0)
	{
		std::cout << this->Name << " is out of energy " << std::endl;
		return ;
	}
	else
		this->energyPoints--;
	std::cout << this->Name << " is reparing +" << amount << std::endl;
	if(this->hitPoint + amount >= 10)
		this->hitPoint = 10;
	else
		this->hitPoint = this->hitPoint + amount;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;
	
}


#include "ClapTrap.hpp"

/* ClapTrap::ClapTrap()
{
} */

ClapTrap::ClapTrap(ClapTrap const &value)
{
	std::cout << "copy constructor ClapTrap" << std::endl;
	this->Name = value.Name;
	this->hitPoint = value.hitPoint;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	
}

ClapTrap &ClapTrap::operator=(ClapTrap const &value)
{
	std::cout << " ClapTrap Copy assignment operator called " << std::endl;
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
	std::cout << this->Name << " ClapTrap is being killed by YOU " << std::endl;
}

//------------------------------------------------------

ClapTrap::ClapTrap(std::string name)
{
	this->attackDamage = 0;
	this->hitPoint = 10;
	this->energyPoints = 10;
	this->Name = name;
	std::cout << "ClapTrap constructor is called for " << this->Name  << std::endl;
}


void ClapTrap::attack(const std::string &target)
{
	if(this->energyPoints <= 0)
	{
		std::cout << this->Name << " is out of energy " << std::endl;
		return ;
	}
	else
		this->energyPoints--;
	std::cout << this->Name << " ClapTrap is attacking " << target << " and causing "<< this->attackDamage << " damage " << std::endl;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
	this->hitPoint = this->hitPoint - amount;
	std::cout << this->Name << " ClapTrap is taking damage -" << amount << std::endl;	
	if(this->hitPoint < 0)
		this->hitPoint = 0;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->hitPoint == 0)
	{
		std::cout << this->Name << " ClapTrap is dead cant be repared " << std::endl;
		return ;
	}
	if(this->energyPoints <= 0)
	{
		std::cout << this->Name << " ClapTrap is out of energy " << std::endl;
		return ;
	}
	else
		this->energyPoints--;
	std::cout << this->Name << " ClapTrap reparing +" << amount << std::endl;
	if(this->hitPoint + amount >= 10)
		this->hitPoint = 10;
	else
		this->hitPoint = this->hitPoint + amount;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;
	
}


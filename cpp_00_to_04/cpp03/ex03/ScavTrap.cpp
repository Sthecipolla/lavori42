#include "ScavTrap.hpp"

/* ScavTrap::ScavTrap()
{
} */

ScavTrap::ScavTrap(ScavTrap const &value)
{
	this->Name = value.Name;
	this->hitPoint = value.hitPoint;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	
}

ScavTrap &ScavTrap::operator=(ScavTrap const &value)
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

ScavTrap::~ScavTrap()
{
	std::cout << this->Name << " is being killed by YOU " << std::endl;
}

//------------------------------------------------------

ScavTrap::ScavTrap(std::string name)
{
	this->attackDamage = 20;
	this->hitPoint = 100;
	this->energyPoints = 50;
	this->Name = name;
	std::cout << "IS BOOOOOOOORN " << this->Name  << std::endl;
}


void ScavTrap::attack(const std::string &target)
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

void ScavTrap::takeDamage(unsigned int amount)
{
	
	this->hitPoint = this->hitPoint - amount;
	std::cout << this->Name << " is taking damage -" << amount << std::endl;	
	if(this->hitPoint < 0)
		this->hitPoint = 0;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;

}

void ScavTrap::beRepaired(unsigned int amount)
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

void ScavTrap::guardGate()
{
	std::cout << this->Name <<" is now in Gate keeper mode" << std::endl;
}
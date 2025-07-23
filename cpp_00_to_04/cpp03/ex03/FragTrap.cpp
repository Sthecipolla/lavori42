#include "FragTrap.hpp"

/* FragTrap::FragTrap()
{
} */

FragTrap::FragTrap(FragTrap const &value)
{
	this->Name = value.Name;
	this->hitPoint = value.hitPoint;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	
}

FragTrap &FragTrap::operator=(FragTrap const &value)
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

FragTrap::~FragTrap()
{
	std::cout << this->Name << " is being killed by YOU " << std::endl;
}

//------------------------------------------------------

FragTrap::FragTrap(std::string name)
{
	this->attackDamage = 30;
	this->hitPoint = 100;
	this->energyPoints = 100;
	this->Name = name;
	std::cout << "IS BOOOOOOOORN " << this->Name  << std::endl;
}


void FragTrap::attack(const std::string &target)
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

void FragTrap::takeDamage(unsigned int amount)
{
	
	this->hitPoint = this->hitPoint - amount;
	std::cout << this->Name << " is taking damage -" << amount << std::endl;	
	if(this->hitPoint < 0)
		this->hitPoint = 0;
	std::cout << "energy points: " << this->energyPoints << " and hitpoint: " << this->hitPoint << std::endl;

}

void FragTrap::beRepaired(unsigned int amount)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << this->Name << " has request an high Fives :) Guys" << std::endl;
}
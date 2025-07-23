#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

class ScavTrap
{
private:
	std::string Name;
	int hitPoint;
	int energyPoints;
	int attackDamage;

public:
	/*--------------------------------*/
//	ClapTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &value);
	ScavTrap &operator=(ScavTrap const &value);
	~ScavTrap();

	/*--------------------------------*/
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
	/*--------------------------------*/

};
#endif
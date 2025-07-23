#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

class DiamondTrap
{
private:
	std::string Name;
	int hitPoint;
	int energyPoints;
	int attackDamage;

public:
	/*--------------------------------*/
//	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &value);
	DiamondTrap &operator=(DiamondTrap const &value);
	~DiamondTrap();

	/*--------------------------------*/
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	/*--------------------------------*/

};
#endif
#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

class ClapTrap
{
private:
	std::string Name;
	int hitPoint;
	int energyPoints;
	int attackDamage;

public:
	/*--------------------------------*/
//	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &value);
	ClapTrap &operator=(ClapTrap const &value);
	~ClapTrap();

	/*--------------------------------*/
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	/*--------------------------------*/

};
#endif
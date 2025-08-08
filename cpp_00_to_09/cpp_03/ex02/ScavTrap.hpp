#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

class ScavTrap : public ClapTrap
{


public:
	/*--------------------------------*/

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
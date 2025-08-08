#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	/*--------------------------------*/
//	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &value);
	FragTrap &operator=(FragTrap const &value);
	~FragTrap();

	/*--------------------------------*/
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void highFivesGuys(void);
	/*--------------------------------*/

};
#endif
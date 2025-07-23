#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

class FragTrap
{
private:
	std::string Name;
	int hitPoint;
	int energyPoints;
	int attackDamage;

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
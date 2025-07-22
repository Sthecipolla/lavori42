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
	ClapTrap();
	ClapTrap(ClapTrap const &value);
	ClapTrap &operator=(ClapTrap const &value);
	~ClapTrap();
	/*--------------------------------*/
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	/*--------------------------------*/
	// Getters
	std::string getName() const;
	int getHitPoint() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	
	// Setters
	void setName(const std::string &name);
	void setHitPoint(int hitPoint);
	void setEnergyPoints(int energyPoints);
	void setAttackDamage(int attackDamage);
};
#endif
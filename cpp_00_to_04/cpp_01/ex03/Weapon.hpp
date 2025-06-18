#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string name);
	std::string getType();
	void setType(std::string type);
};

#endif
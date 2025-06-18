#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

class Zombie
{

private:
	std::string name;

public:
	void announce(void);
	void setZombieName(std::string name);
	~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif
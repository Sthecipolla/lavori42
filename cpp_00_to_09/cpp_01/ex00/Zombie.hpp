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
	Zombie(std::string name);
	~Zombie();
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif
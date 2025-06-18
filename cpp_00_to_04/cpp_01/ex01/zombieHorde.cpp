#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombiesHorde;
	int i;

	zombiesHorde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombiesHorde[i].setZombieName(name);
		i++;
	}
	return (zombiesHorde);
}
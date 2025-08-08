#include "ClapTrap.hpp"

int main()
{
	ClapTrap first("perez");
	ClapTrap second("carlos");

	first.attack("carlos");
	second.takeDamage(0);
	second.beRepaired(120);
	second.attack("perez");
	first.takeDamage(0);
	first.beRepaired(123123);
	return (0);
}
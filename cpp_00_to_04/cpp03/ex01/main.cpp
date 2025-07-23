#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap first("perez");
	ClapTrap second("carlos");
	ScavTrap scav("terco");

	first.attack("carlos");
	second.takeDamage(0);
	second.beRepaired(120);
	second.attack("perez");
	first.takeDamage(0);
	first.beRepaired(123123);
	scav.attack("carlos");
	second.takeDamage(20);
	second.beRepaired(120);
	scav.guardGate();
	return (0);
}
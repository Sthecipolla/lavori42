#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my \
	7XL-double-cheese-triple-pickle-specialketchup burger.  I really do!"
			  << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
	enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}
void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\
	I’ve been coming for \
	years, whereas you started working here just last month."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	std::string arr[] = {"debug", "info", "warning", "error"};
	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	i = 0;
	while (i < 4)
	{
		if (arr[i] == level)
			break;
		i++;
	}
	if (i < 4)
		(this->*functions[i])();
}

Harl::Harl()
{
}

Harl::~Harl()
{
}
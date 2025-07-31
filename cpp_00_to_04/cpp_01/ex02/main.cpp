#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
	std::string variable_invariable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable_invariable;
	std::string &stringREF = variable_invariable;
	std::cout << &variable_invariable << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << variable_invariable << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
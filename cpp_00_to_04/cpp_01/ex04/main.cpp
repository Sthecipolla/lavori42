
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

int main(int argc, char **argv)
{
	std::string name;
	std::string search = "main";
	std::string newWorld = "ciao";
	std::string newString;
	std::string::size_type check;
	size_index;

	if (argc != 2)
		return (1);
	name.append(argv[1]);
	name.append(".replace");
	std::ifstream read(argv[1]);
	std::ofstream write(name.c_str());
	std::string print;
	while (getline(read, print))
	{
		std::cout << index << std::endl;

		while (index != std::string::npos)
		{
			index = print.find(search, );
			std::cout << index << std::endl;
			if (index == 0)
			{
				newString.append(newWorld);
				newString.append(print.substr(search.length(), print.length()));
			}
			else
			{
				newString.append(print.substr(0, index));
				newString.append(newWorld);
				newString.append(print.substr(newString.length(), print.length()));
			}
		}

		write << newString << std::endl;
		newString.clear();
	}
	return (0);
}
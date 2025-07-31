#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

std::string creNewString(std::string print, std::string search,
						 std::string newWorld)
{

	size_t index = 0;
	std::string retString;

	while (index != std::string::npos)
	{
		index = print.find(search);
		if (index == std::string::npos)
			retString.append(print);
		else if (index == 0)
		{
			retString.append(newWorld);
			retString.append(print.substr(search.length(), print.length() - 1));
			print = print.substr(index + search.length());
		}
		else
		{
			retString.append(print.substr(0, index));
			retString.append(newWorld);
			retString.append(print.substr(index + search.length(), print.length() - 1));
			print = print.substr(index + search.length());
		}
	}
	return (retString);
}

int is_empty(std::string file, std::string s1, std::string s2)
{
	if (file.empty() || s1.empty() || s2.empty())
		return 0;
	return 1;
}

int main(int argc, char **argv)
{
	std::string name;
	std::string print;
	std::string newString;

	if (argc != 4 || is_empty(argv[1], argv[2], argv[3]) == 0)
		return (1);
	name.append(argv[1]);
	name.append(".replace");
	std::ifstream read(argv[1]);
	std::ofstream write(name.c_str());
	while (getline(read, print))
	{

		newString = creNewString(print, argv[2], argv[3]);
		write << newString << std::endl;
		newString.clear();
	}
	read.close();
	write.close();
	return (0);
}
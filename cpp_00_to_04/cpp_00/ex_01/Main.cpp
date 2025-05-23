#include <PhoneBook.hpp>


int main()
{
	std::string str;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string Number;
    std::string DarkestSecret;
	PhoneBook PhoBook(std::time(NULL));
	size_t i = 0;
	while(1)
	{
		std::cout << "write a command: ADD | SEARCH | EXIT" << std::endl;
		std::cin >>	str;
		i = 0;
		while ( str.length() > i)
		{
			if(str[i] >='a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			i++;
		}
		if (str.compare("ADD") == 0)
		{
			std::cout << "First name:" << std::endl;
			std::cin >> FirstName;
			std::cout << "Last name:" << std::endl;
			std::cin >> LastName;
			std::cout << "Nickname:" << std::endl;
			std::cin >> Nickname;
			std::cout << "Number:" << std::endl;
			std::cin >> Number;
			std::cout << "Darkest secret:" << std::endl;
			std::cin >> DarkestSecret;
			PhoBook.AddUser(LastName, FirstName, Nickname, Number, DarkestSecret);
		}
		else if (str.compare("SEARCH") == 0)
			PhoBook.SearchUser();
		else if (str.compare("EXIT") == 0)
			PhoBook.Exit();
	}

}

#include <PhoneBook.hpp>


PhoneBook:: PhoneBook(std::time_t time)
{
int i = -1;
while(++i < 8)
	book[i].SetTime(time);
}

void	PhoneBook:: AddUser(std::string LastName, std::string FirstName,\
	std::string NickName, std::string Number, std::string secret)
{
	int			i = 0;
	std::time_t	time;
	int			pos;

	time = book[i].GetTime();
	pos = 0;
	while(i < 8)
	{
		if(std::difftime(time, book[i].GetTime()) > 0)
		{
			time = book[i].GetTime();
			pos = i;
		}
		i++;
	}

	book[pos].SetFirstName(FirstName);
	book[pos].SetLastName(LastName);
	book[pos].SetNickname(NickName);
	book[pos].SetNumber(Number);
	book[pos].SetTime(std::time(NULL));
	book[pos].SetDarkestSecret(secret);
}



int PhoneBook::select()
{
	std::string input;
	int i;

    std::cout << "Enter the index of the contact: ";
    std::getline(std::cin, input);
    i = std::atoi(input.c_str());
	i--;

	if(i < 0 || i > 7)
	{
		std::cout << "Error invalid value for the index" << std::endl;
		return FALSE;
	}
	if(book[i].GetFirstName().empty() == TRUE)
		return FALSE;
	std::cout << book[i].GetFirstName() << std::endl;
	std::cout << book[i].GetLastName() << std::endl;
	std::cout << book[i].GetNickname() << std::endl;
	std::cout << book[i].GetNumber() << std::endl;
	std::cout << book[i].GetDarkestSecret() << std::endl;
	return TRUE;
}



void	PhoneBook:: SearchUser(void)
{
	int			i = 0;
	std::time_t	time;
	int			pos;
	std::string	str;

	if(book[0].GetNickname().compare("") == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::cout <<"index     |first name|last name |nickname  |" << std:: endl;

	time = book[i].GetTime();
	pos = 0;
	while(i < 8)
	{
		if(book[i].GetNickname().compare("") != 0)
		{
			std::cout << i + 1 << "         |";
			str = book[i].GetFirstName();
			if (str.length() > 10) {
   				 str.resize(10);
				str[9] = '.';
			} else {
				str.resize(10, ' ');
			}
			std::cout << str << "|";
			str = book[i].GetLastName();
			if (str.length() > 10) {
				str.resize(10);
				str[9] = '.';
			} else {
				str.resize(10, ' ');
			}
			std::cout << str << "|";
			str = book[i].GetNickname();
			if (str.length() > 10) {
				str.resize(10);
				str[9] = '.';
			} else {
				str.resize(10, ' ');
			}
			std::cout << str << "|" << std::endl;
		}
		i++;
	}
	select();
}

void	PhoneBook:: Exit(void)
{
	exit(0);
}


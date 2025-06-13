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
	if(book[pos].GetFirstName().compare("") != 0)
	{
		std::cout << "no contacts available." << std::endl;
		return;
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
	int i;

	try{
	std::cin >> i;
	}catch(std::exception &e){
		std::cout << "Error invalid value for the index" << std::endl;
		return (FALSE);
	}
	if(i < 0 || i > 10)
	{
		std::cout << "Error invalid value for the index" << std::endl;
		return FALSE;
	}
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
	std::cout <<"index     |first name|last name |nickname" << std:: endl;

	time = book[i].GetTime();
	pos = 0;
	while(i < 8)
	{
		if(book[i].GetNickname().compare("") != 0)
		{
			std::cout << i << "         |";
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
	if(select() == FALSE)
		return;
}

void	PhoneBook:: Exit(void)
{
	exit(0);
}


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

void	PhoneBook:: SearchUser(int i)
{
	std::cout <<"index     |first name|last name |nickname" << std:: endl;
	int			i = 0;
	std::time_t	time;
	int			pos;
	std::string	str;

	time = book[i].GetTime();
	pos = 0;
	while(i < 8)
	{
		if(book->GetNickname().compare("") != 0)
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
	std::cin >> str;
	i = std::stoi(str);
	if(i < 0 || i > 10)
		return ;
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
}

void	PhoneBook:: Exit(void)
{
	exit(0);
}


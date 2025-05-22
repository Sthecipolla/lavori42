# include <include.h>

class Contact;

class PhoneBook
{
	private :

		Contact book[8];

	PhoneBook(std::time_t time)
	{
		int i = -1;
		while(++i < 8)
			book[i].SetTime(time);
	}

	public :

		void	AddUser(std::string LastName, std::string FirstName,\
			std::string NickName, std::string Number)
		{
			int			i = 0;
			std::time_t	Time;
			int			pos;

			Time = book[i].getTime();
			pos = 0;
			while(i < 8)
			{
				if(book[i].getTime < time)
				{
					Time = book[i].getTime;
					pos = i;
				}
				i++;
			}
			book[pos].SetFirstName(FirstName);
			book[pos].SetLastName(LastName);
			book[pos].SetNickName(NickName);
			book[pos].SetNumber(Number);
			book[pos].SetTime(std::time(nullptr));
		}

		void	SearchUser(std::string name, std::string number)
		{
			std::cout << "first name	last name	nickname	number";
		}
}


# include <include.h>
#include <PhoneBook.hpp>

class Contact
{
  private:
	std::time_t Time;
	std::string Nickname;
	std::string Number;
	std::string FirstName;
	std::string LastName;

	public:

		std::time_t	GetTime()
		{
			return (Time);
		}

		void SetTime(std::time_t Time)
		{
			this->Time = Time;
		}

		std::string GetNickname()
		{
			return (this->Nickname);
		}


		void SetNickname(std::string Nickname)
		{
			this->Nickname = Nickname;
		}


		std::string GetNumber()
		{
			return (this->Number);
		}


		void SetNumber(std::string Number)
		{
			this->Number = Number;
		}


		std::string GetFirstName()
		{
			return (this->FirstName);
		}

		void SetFirstName(std::string FirstName)
		{
			this->FirstName = FirstName;
		}

		std::string GetLastName()
		{
			return (this->LastName);
		}

		void SetLastName(std::string LastName)
		{
			this->LastName = LastName;
		}

}

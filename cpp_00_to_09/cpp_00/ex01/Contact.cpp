#include <PhoneBook.hpp>

std::string Contact::GetDarkestSecret()
{
	return (this->DarkestSecret);
}

void Contact::SetDarkestSecret(std::string DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

std::time_t Contact::GetTime()
{
	return (Time);
}

void Contact::SetTime(std::time_t Time)
{
	this->Time = Time;
}

std::string Contact::GetNickname()
{
	return (this->Nickname);
}

void Contact::SetNickname(std::string Nickname)
{
	this->Nickname = Nickname;
}

std::string Contact::GetNumber()
{
	return (this->Number);
}

void Contact::SetNumber(std::string Number)
{
	this->Number = Number;
}

std::string Contact::GetFirstName()
{
	return (this->FirstName);
}

void Contact::SetFirstName(std::string FirstName)
{
	this->FirstName = FirstName;
}

std::string Contact::GetLastName()
{
	return (this->LastName);
}

	void Contact::SetLastName(std::string LastName)
	{
		this->LastName = LastName;
	}

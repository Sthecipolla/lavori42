#include <iostream>
#include <stdio.h>
#include <string>
# include <ctime>
#include <cstdlib>

#define FALSE 0

#define TRUE 1

class Contact
{
private:
	std::time_t Time;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string Number;
    std::string DarkestSecret;

public:

    void SetFirstName(std::string FirstName);
    void SetLastName(std::string LastName);
    void SetNickname(std::string Nickname);
    void SetNumber(std::string Number);
    void SetDarkestSecret(std::string DarkestSecret);
	void SetTime(std::time_t Time);

    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickname();
    std::string GetNumber();
    std::string GetDarkestSecret();
	std::time_t GetTime();

};

class PhoneBook
{
	private :

		Contact book[8];
        int select();

	public :
		PhoneBook(std::time_t time);
		void	AddUser(std::string LastName, std::string FirstName,\
			std::string NickName, std::string Number, std::string secret);
		void	SearchUser();
		void	Exit(void);
};

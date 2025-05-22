#include <megaphone.h>

//using namespace std;

int	main(int argc, char **argv)
{
	std::string s1;
	size_t		i;
	size_t		j = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while(j < (size_t) argc)
	{
		s1.assign(argv[j]);
		i = 0;
		while ( s1.length() > i)
		{
			if(s1[i] >='a' && s1[i] <= 'z')
				s1[i] = s1[i] - 32;
			i++;
		}
		std::cout << s1;
		j ++;
	}
	std::cout << std::endl;
	return (0);
}

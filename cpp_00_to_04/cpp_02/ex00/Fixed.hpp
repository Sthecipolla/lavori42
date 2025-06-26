#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int value;
	static const int bits;

public:
	Fixed();
	Fixed(Fixed const &fxd);
	Fixed &operator=(Fixed const &c);
	~Fixed();
	int getRawBits(void);
	void setRawBits(int const raw);
};

#endif
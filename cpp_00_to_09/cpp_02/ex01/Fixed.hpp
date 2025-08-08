#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int bits;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);

	Fixed(Fixed const &fxd);
	Fixed &operator=(Fixed const &c);

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);

	~Fixed();
};
std::ostream &operator<<(std::ostream &os, const Fixed &fxd);

#endif
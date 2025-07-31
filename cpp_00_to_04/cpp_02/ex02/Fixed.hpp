#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

#define TRUE 1

#define FALSE 0

#define EPSILON FLT_EPSILON

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
	/*-------------------------------*/
	Fixed operator+(Fixed const &c);
	Fixed operator-(Fixed const &c);
	Fixed operator*(Fixed const &c);
	Fixed operator/(Fixed const &c);
	/*-------------------------------*/
	bool operator>(Fixed const &c);
	bool operator<(Fixed const &c);
	bool operator<=(Fixed const &c);
	bool operator>=(Fixed const &c);
	bool operator==(Fixed const &c);
	bool operator!=(Fixed const &c);
	/*-------------------------------*/
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	/*-------------------------------*/
	static float min(Fixed &first, Fixed &second);
	static float min(Fixed const &first, Fixed const &second);
	static float max(Fixed &first, Fixed &second);
	static float max(Fixed const &first, Fixed const &second);
};
std::ostream &operator<<(std::ostream &os, const Fixed &fxd);

#endif
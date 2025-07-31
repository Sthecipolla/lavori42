#include "Fixed.hpp"

const int Fixed::bits = 8;

static float value_abs(float a, float b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (float)(1 << bits));
}

Fixed::Fixed(Fixed const &fxd)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = fxd.value;
}

Fixed &Fixed::operator=(Fixed const &c)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &c)
	{
		this->value = c.value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((this->value) / (float)(1 << bits));
}

int Fixed::toInt(void) const
{
	return (int)(this->value) / (1 << bits);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fxd)
{
	os << fxd.toFloat();
	return os;
}

/*------------------------------------------------------------------------------------*/

Fixed Fixed::operator+(Fixed const &c)
{
	return (Fixed(this->toFloat() + c.toFloat()));
}

Fixed Fixed::operator-(Fixed const &c)
{
	return (Fixed(this->toFloat() - c.toFloat()));
}

Fixed Fixed::operator/(Fixed const &c)
{
	return (Fixed(this->toFloat() / c.toFloat()));
}

Fixed Fixed::operator*(Fixed const &c)
{
	return (Fixed(this->toFloat() * c.toFloat()));
}

bool Fixed::operator>(Fixed const &c)
{
	if (value_abs(this->toFloat(), c.toFloat()) <= EPSILON)
		return (FALSE);
	if (this->toFloat() > c.toFloat())
		return (TRUE);
	return (FALSE);
}

bool Fixed::operator<(Fixed const &c)
{
	if (value_abs(this->toFloat(), c.toFloat()) <= EPSILON)
		return (FALSE);
	if (this->toFloat() < c.toFloat())
		return (TRUE);
	return (FALSE);
}

bool Fixed::operator<=(Fixed const &c)
{
	if (value_abs(this->toFloat(), c.toFloat()) <= EPSILON ||
		this->toFloat() < c.toFloat())
		return (TRUE);
	return (FALSE);
}

bool Fixed::operator>=(Fixed const &c)
{
	if (value_abs(this->toFloat(), c.toFloat()) <= EPSILON ||
		this->toFloat() > c.toFloat())
		return (TRUE);
	return (FALSE);
}

bool Fixed::operator==(Fixed const &c)
{
	if (value_abs(this->toFloat(), c.toFloat()) <= EPSILON)
		return (TRUE);
	return (FALSE);
}

bool Fixed::operator!=(Fixed const &c)
{
	if (value_abs(this->toFloat(), c.toFloat()) > EPSILON)
		return (TRUE);
	return (FALSE);
}

Fixed &Fixed::operator--()
{
	value--;
	return *this;
}

Fixed &Fixed::operator++()
{

	value++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}
// espilon 0.000001
float Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first.toFloat());
	return (second.toFloat());
}

float Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first.value < second.value)
		return (first.toFloat());
	return (second.toFloat());
}

float Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first.toFloat());
	return (second.toFloat());
}

float Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first.value > second.value)
		return (first.toFloat());
	return (second.toFloat());
}

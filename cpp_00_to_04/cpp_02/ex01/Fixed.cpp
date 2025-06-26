#include "Fixed.hpp"

const int Fixed::bits = 8;

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

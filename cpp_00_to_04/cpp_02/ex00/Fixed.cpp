#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
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

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}


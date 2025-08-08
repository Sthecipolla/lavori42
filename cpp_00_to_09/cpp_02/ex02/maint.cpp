#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);
	Fixed e = Fixed(2.5f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;

	std::cout << "\nArithmetic:" << std::endl;
	std::cout << "b + c = " << b + c << std::endl;
	std::cout << "c - b = " << c - b << std::endl;
	std::cout << "b * e = " << b * e << std::endl;
	std::cout << "c / e = " << c / e << std::endl;

	std::cout << "\nComparison:" << std::endl;
	std::cout << "b > e: " << (b > e) << std::endl;
	std::cout << "b < e: " << (b < e) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != d: " << (b != d) << std::endl;

	std::cout << "\nIncrement/Decrement:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "\nMin/Max:" << std::endl;
	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

	const Fixed f1(7.5f), f2(3.1f);
	std::cout << "min(f1, f2): " << Fixed::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2): " << Fixed::max(f1, f2) << std::endl;

	return 0;
}
#include "aMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // copy assignment implementation
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}
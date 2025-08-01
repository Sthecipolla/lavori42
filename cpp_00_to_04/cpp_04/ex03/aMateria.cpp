#include "aMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria constructor called" << std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    this->type = other.type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "no right object" << std::endl;
}
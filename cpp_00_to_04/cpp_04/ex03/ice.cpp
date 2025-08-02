#include "ice.hpp"


Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    this->type = other.type;

}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice( *this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}
#include "character.hpp"

Character::Character(std::string name)
{
    int i;

    i = 0;
    std::cout << "Character constructor called" << std::endl;
    while(i < 4)
    {
        this->materia[i] = NULL;
        i++;
    }
    this->name = name;
}

Character::Character(const Character& other) 
{
    int i;
    
    i = 0;
    std::cout << "Character copy constructor called" << std::endl;
    while(i < 4)
    {
        this->materia[i] = other.materia[i];
        i++;
    }
}

Character& Character::operator=(const Character& other)
{
    int i;

    i = 0;
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other) {
        while(i < 4)
        {
            this->materia[i] = other.materia[i];
            i++;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
}

std::string const Character::&getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    int i;

    i = 0;
    while(i < 4)
    {
        if( this->materia[i] == NULL)
            this->materia[i] = m;
        i++;
    }
}

void Character::unequip(int idx)
{
    this->materia[i] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    
}
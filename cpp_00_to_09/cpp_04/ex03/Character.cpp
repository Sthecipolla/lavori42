#include "Character.hpp"
#include "AMateria.hpp"

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
    this->name = other.name;
    while(i < 4)
    {
        if (other.materia[i] != NULL)
            this->materia[i] = other.materia[i]->clone();
        else
            this->materia[i] = NULL;
        i++;
    }
}

Character& Character::operator=(const Character& other)
{
    int i;

    i = 0;
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        while(i < 4)
        {
            if (this->materia[i] != NULL)
                delete this->materia[i];
            if (other.materia[i] != NULL)
                this->materia[i] = other.materia[i]->clone();
            else
                this->materia[i] = NULL;
            i++;
        }
    }
    return *this;
}

Character::~Character()
{
    int i;

    i = 0;
    std::cout << "Character destructor called" << std::endl;
    while (i < 4)
    {
        if(this->materia[i] != NULL)
            delete this->materia[i];
        i++;
    }
   
}

std::string const& Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    int i;

    if (m == NULL)
        return;
        
    i = 0;
    while(i < 4)
    {
        if( this->materia[i] == NULL)
        {
            this->materia[i] = m;
            return;
        }
        i++;
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || this->materia[idx] == NULL)
        return;
    this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || this->materia[idx] == NULL)
        return;
    this->materia[idx]->use(target);
}
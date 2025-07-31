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
    this->name = other.name;
    while(i < 4)
    {
        unequip(i);
        if (other.materia[i] != NULL)
            this->materia[i] = other.materia[i]->clone(); // Deep copy using clone()
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
    this->name = other.name;
    if (this != &other)
    {
        unequip(i);
        while(i < 4)
        {
            if (other.materia[i] != NULL)
                this->materia[i] = other.materia[i]->clone(); // Deep copy using clone()
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
        delete this->materia[i];
        i++;
    }
    i = 0;
    while (i < this->left.size())
    {
        delete this->left[i];
        i++;
    }
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
    if (idx < 0 || idx > || this->materia[idx] == NULL)
        return;
    this->left.resize(this->left.size() + 1);
    this->left.push_back(this->materia[idx]);
    this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) : AMateria::use(target)
{
    if (materia[i] == NULL)
        return;
    std::cout << "use" << this->materia[i] << std::endl;
}
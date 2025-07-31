#include "materiaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
    int i;
    
    i = 0;
    std::cout << "MateriaSource constructor called" << std::endl;
    while(i < 4)
    {
        this->store[i] = NULL;
        i ++;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    int i;
    
    i = 0;
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        while(i < 4)
        {
            this->store[i] = NULL;
            i ++;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* mate)
{
    int i;
    
    i = 0;
    while(i < 4)
    {
        if( this->store[i] == NULL)
            this->store[i] = mate;
        i ++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
   int i;
    
    i = 0;
    while(i < 4)
    {
        if( this->store[i]->type == type)
            return this->store[i];
        i ++;
    }
    return 0;
}
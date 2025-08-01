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
    int i;
    
    i = 0;
    std::cout << "MateriaSource copy constructor called" << std::endl;
    while(i < 4)
    {
        this->store[i] =  other.store[i]->clone();
        i ++;
    }
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
            this->store[i] =  other.store[i]->clone();
            i ++;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    int i;
    
    i = 0;
    while(i < 4)
    {
        if (this->store[i] == NULL)
        {
            i++;
            continue;
        }
        else
        {
            delete this->store[i];
        }
        i++;
    }
}

void MateriaSource::learnMateria(AMateria* mate)
{
    int i;
    
    i = 0;
    while(i < 4)
    {
        if( this->store[i] == NULL)
        {
            this->store[i] = mate;
            break ;
        }
        i ++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
   int i;
    
    i = 0;
    while(i < 4)
    {
        if(this->store[i] == NULL)
        {
            i++;
            continue;
        }
        if(this->store[i]->getType() == type)
            return this->store[i]->clone();
        i ++;
    }
    return 0;
}
#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "iMateriaSource.hpp"

class MateriaSource : IMateriaSource 
{
    private :
        AMateria *store[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();

};

#endif
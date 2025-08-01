#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "iMateriaSource.hpp"

class MateriaSource : public IMateriaSource 
{
    private :
        AMateria *store[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

};

#endif
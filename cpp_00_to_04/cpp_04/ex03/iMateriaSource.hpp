#ifndef I_MATERIAL_SOURCE_H
#define I_MATERIAL_SOURCE_H

#include "aMateria.hpp"

class IMateriaSource 
{
    public: 
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;


};



#endif
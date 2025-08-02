#ifndef ICE_H
#define ICE_H

#include "aMateria.hpp"

class Ice : public AMateria
{

    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
    
};

#endif
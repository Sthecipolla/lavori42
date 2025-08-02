#ifndef AMATERIAL_H
#define AMATERIAL_H

#include "iCharacter.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria(std::string const &type);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();
};


#endif
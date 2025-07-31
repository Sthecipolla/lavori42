#ifndef AMATERIAL_H
#define AMATERIAL_H

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
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        ~AMateria();
};

#endif
#ifndef CURE_H
#define CURE_H

#include "aMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
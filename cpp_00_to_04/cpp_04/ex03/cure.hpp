#ifndef CURE_H
#define CURE_H

#include "aMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure clone();
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        ~Cure();
        Cure* clone() const;
        void use(ICharacter& target);
};

#endif
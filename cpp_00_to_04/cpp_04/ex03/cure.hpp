#ifndef CURE_H
#define CURE_H

#include "aMateria.hpp"

class Cure : AMateria
{
    public:
        Cure clone() class Cure
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        ~Cure();
};

#endif
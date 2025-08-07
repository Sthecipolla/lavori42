#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include <vector>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *materia[4];
        std::vector<AMateria *> left;

    public:
        Character(std::string name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
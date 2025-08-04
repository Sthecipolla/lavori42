#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Share.hpp"

class Brain
{
    protected :
        std::string ideas[100];
    public :
        Brain();
		Brain(Brain const &value);
        Brain &operator=(const Brain &value);
        ~Brain();
};

#endif
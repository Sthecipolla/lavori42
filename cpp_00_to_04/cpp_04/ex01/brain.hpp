#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "share.hpp"

class Brain
{
    protected :
        std::string ideas[100];
    public :
        Brain();
		Brain(const Brain &value);
        Brain &operator=(const Brain &value);
		virtual ~Brain();
}



#endif
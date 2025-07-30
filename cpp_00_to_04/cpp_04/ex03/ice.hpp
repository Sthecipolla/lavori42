#ifndef ICE_H
#define ICE_H

class Ice
{
    
    public:
        Ice clone()
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();
    
};

#endif
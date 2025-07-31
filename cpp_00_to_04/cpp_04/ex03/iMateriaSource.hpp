#ifndef I_MATERIAL_SOURCE_H
#define I_MATERIAL_SOURCE_H

class IMateriaSource {
public:
    IMateriaSource();
    IMateriaSource(const IMateriaSource& other);
    IMateriaSource& operator=(const IMateriaSource& other);
    ~IMateriaSource();
    
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;


};



#endif
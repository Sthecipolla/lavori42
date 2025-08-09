#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp" 


/* int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
} */

void test_basic_functionality() {
    std::cout << "=== BASIC FUNCTIONALITY TEST ===" << std::endl;
    
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter *me = new Character("me");
    ICharacter *bob = new Character("bob");
    
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
}

void test_copy_functionality() {
    std::cout << "=== COPY FUNCTIONALITY TEST ===" << std::endl;
    
    Character original("original");
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    AMateria *ice = src->createMateria("ice");
    AMateria *cure = src->createMateria("cure");
    
    original.equip(ice);
    original.equip(cure);
    
    // Test copy constructor
    Character copy1(original);
    
    // Test assignment operator
    Character copy2("copy2");
    copy2 = original;
    
    ICharacter *target = new Character("target");
    
    std::cout << "\nOriginal using materia:" << std::endl;
    original.use(0, *target);
    original.use(1, *target);
    
    std::cout << "\nCopy1 using materia:" << std::endl;
    copy1.use(0, *target);
    copy1.use(1, *target);
    
    std::cout << "\nCopy2 using materia:" << std::endl;
    copy2.use(0, *target);
    copy2.use(1, *target);
    
    delete target;
    delete src;
    std::cout << std::endl;
}

void test_unequip_functionality() {
    std::cout << "=== UNEQUIP FUNCTIONALITY TEST ===" << std::endl;
    
    Character character("test");
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    AMateria *ice = src->createMateria("ice");
    AMateria *cure = src->createMateria("cure");
    
    character.equip(ice);
    character.equip(cure);
    
    ICharacter *target = new Character("target");
    
    std::cout << "\nUsing equipped materia:" << std::endl;
    character.use(0, *target);
    character.use(1, *target);
    
    std::cout << "\nUnequipping slot 0:" << std::endl;
    character.unequip(0);
    
    std::cout << "\nTrying to use unequipped slot 0 (should do nothing):" << std::endl;
    character.use(0, *target);
    
    std::cout << "\nUsing slot 1 (still equipped):" << std::endl;
    character.use(1, *target);
    
    delete target;
    delete src;
    std::cout << std::endl;
    delete ice;
    //delete cure;
}

void test_inventory_limits() {
    std::cout << "=== INVENTORY LIMITS TEST ===" << std::endl;
    
    Character character("test");
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "\nEquipping 4 materia (max inventory):" << std::endl;
    for (int i = 0; i < 4; i++) {
        AMateria *mat = src->createMateria("ice");
        character.equip(mat);
        std::cout << "Equipped materia " << i << std::endl;
    }
    
    std::cout << "\nTrying to equip 5th materia (should be ignored):" << std::endl;
    AMateria *extra = src->createMateria("cure");
    character.equip(extra);
    delete extra; // Must delete since it wasn't equipped
    
    ICharacter *target = new Character("target");
    
    std::cout << "\nUsing all equipped materia:" << std::endl;
    for (int i = 0; i < 4; i++) {
        character.use(i, *target);
    }
    
    delete target;
    delete src;
    std::cout << std::endl;
}

void test_invalid_operations() {
    std::cout << "=== INVALID OPERATIONS TEST ===" << std::endl;
    
    Character character("test");
    ICharacter *target = new Character("target");
    
    std::cout << "\nTesting invalid slot indices:" << std::endl;
    character.use(-1, *target);  // Invalid negative index
    character.use(4, *target);   // Invalid high index
    character.use(0, *target);   // Valid index but empty slot
    
    character.unequip(-1);       // Invalid negative index
    character.unequip(4);        // Invalid high index
    character.unequip(0);        // Valid index but empty slot
    
    character.equip(NULL);       // NULL materia
    
    delete target;
    std::cout << std::endl;
}

int main()
{
    test_basic_functionality();
    test_copy_functionality();
    test_unequip_functionality();
    test_inventory_limits();
    test_invalid_operations();
    
    std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}

#include "cure.hpp"

cure::cure() {
    std::cout << "cure constructor called" << std::endl;
}

cure::cure(const cure& other) {
    std::cout << "cure copy constructor called" << std::endl;
}

cure& cure::operator=(const cure& other) {
    std::cout << "cure copy assignment operator called" << std::endl;
    if (this != &other) {
        // copy assignment implementation
    }
    return *this;
}

cure::~cure() {
    std::cout << "cure destructor called" << std::endl;
}
#include "ice.hpp"


Ice::Ice() {
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &other) {
        // copy assignment implementation
    }
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}
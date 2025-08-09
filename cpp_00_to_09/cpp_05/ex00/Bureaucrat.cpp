
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) 
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    this->name = name;
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    this->name = other->name;
    this->grade = other->grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) {
       this->name = other->name;
       this->grade = other->grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::getName() const
{
    return this->name
}

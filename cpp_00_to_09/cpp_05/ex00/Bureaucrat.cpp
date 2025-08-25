
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const name, int grade) 
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    this->name = name;
    try
    {
        if (grade > 150)
            throw std::out_of_range("Grade Too High");
        if (grade < 1)
            throw std::out_of_range("Grade Too Low");
        this->grade = grade;
    }catch(const std::out_of_range& e)
    {
        std::cout << "Exception : "<< e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    this->name = other.name;
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) {
       this->name = other.name;
       this->grade = other.grade;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &fxd)
{
	os << fxd.getName();
	return os;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::getName() const
{
    return (this->name);
}


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    //this->name = name;
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : name(other.name){
    std::cout << "Bureaucrat copy constructor called" << std::endl;
   // this->name = other.name;
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
	{
       //this->name = other.name;
       this->grade = other.grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &fxd)
{
	os << fxd.getName() << ", bureaucrat grade " << fxd.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if(this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if(this->grade + 1> 150)
        throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;

}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::signForm(Form *c)
{
	try
	{
		c->beSigned(this);
		std::cout << this->name << " signed " << c->getName() << std::endl;
	}catch(/* Form::GradeTooLowException */ std::exception &sa)
	{
		std::cout<< this->name <<" coulden't sign " << c->getName() << " because: " << sa.what() << std::endl;
	}
}

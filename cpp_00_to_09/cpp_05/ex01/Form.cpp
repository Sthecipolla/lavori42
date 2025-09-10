#include "Form.hpp"
#include <iostream>

Form::Form(int sign, int exe, std::string name) : name(name), gradeToSign(sign), gradeToExecute(exe)
{
	if(exe > 150 || sign > 150)
		throw Form::GradeTooLowException();
	if(exe < 0 || sign < 0)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor called" << std::endl;
	this->sign = false;
}

Form::Form(Form& other) : name(other.getName()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
	this->sign = other.getSign();
}

Form& Form::operator=(Form& other) 
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		this->sign = other.getSign();
	return *this;
}

Form::~Form() 
{
	std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat *c)
{
	if (c->getGrade() >= this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool Form::getSign() const
{
	return (this->sign);
}
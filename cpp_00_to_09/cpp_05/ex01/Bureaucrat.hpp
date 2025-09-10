#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H


#include <unistd.h>
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
		class GradeTooHighException : public std::exception
		{
			public:
    			const char* what() const throw (){
        			return "grade Too hight";
    			}
			
		};
		class GradeTooLowException : public std::exception
		{
			public:
    			const char* what() const throw(){
        			return "grade Too low";
    		}
		};
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
		//----------------------------------------------------------//
        void incrementGrade();
        void decrementGrade();
		std::string getName() const;
		int getGrade() const;
		void signForm(Form *c);

};
    std::ostream& operator<<(std::ostream &os, const Bureaucrat &fxd);


#endif
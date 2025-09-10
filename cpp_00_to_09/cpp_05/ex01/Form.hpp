#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <unistd.h>
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private :
		std::string const name;
		bool sign;
		int const gradeToSign;
		int const gradeToExecute;
	public :
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
		Form(int sign, int exe, std::string name);
		Form(Form& other);
		Form& operator=(Form& other);
		~Form();
		void beSigned(Bureaucrat *c);
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSign() const;



	

};
    std::ostream& operator<<(std::ostream &os, const Form &fxd);


#endif
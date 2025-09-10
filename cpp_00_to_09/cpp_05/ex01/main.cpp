#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try{
/* 		Bureaucrat siul("siul", 0);
		Bureaucrat lhima("lhima", 0);
		Bureaucrat lhima2("lhima the guy that never jokes", 0); */
		//Bureaucrat c2("lhima the guy that dosent speaks", 0);
		Bureaucrat Mariaccio("Mariaccio", 150);
		//Mariaccio.decrementGrade();
		Bureaucrat Marcaccio("Marcaccio", 62);
		Bureaucrat siul("siul", 1);
		Mariaccio.incrementGrade();
		Mariaccio.decrementGrade();
		std::cout << siul << std::endl; 
		//siul.incrementGrade();
		Form forms(122, 6, "Love form");
		siul.signForm(&forms);
		Mariaccio.signForm(&forms);
	}
	catch(Bureaucrat::GradeTooLowException &sa){
		std::cout << sa.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &c){
		std::cout << c.what() << std::endl;
	}
	catch(Form::GradeTooLowException &a){
		std::cout << a.what() << std::endl;
	}
	catch(Form::GradeTooHighException &v){
		std::cout << v.what() << std::endl;
	}
	catch(std::exception &t)
	{
		std::cout << "error" << std::endl;
	};
	return (0);
}
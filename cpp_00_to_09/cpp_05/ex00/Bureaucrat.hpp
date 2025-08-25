#include <unistd.h>
#include <string>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator<<(Bureaucrat& other);

        void getName() const;
        void getGrade() const;



};
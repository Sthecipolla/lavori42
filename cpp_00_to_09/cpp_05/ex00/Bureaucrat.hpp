#include <unistd.h>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator<<(Bureaucrat& other);

        void getName() const;
        void getGrade() const;



};
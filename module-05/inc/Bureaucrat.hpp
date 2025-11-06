#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <string>

class Bureaucrat
{
  public:
    Bureaucrat(void);
    Bureaucrat(Bureaucrat const& source);
    Bureaucrat(std::string const& name, int grade);
    ~Bureaucrat(void);

    Bureaucrat& operator=(Bureaucrat const& source);

    std::string const&  getName(void) const;
    int                 getGrade(void) const;

    void                incrementGrade(void);
    void                incrementGrade(int i);
    void                decrementGrade(void);
    void                decrementGrade(int i);

    static int const    highestGrade = 1;
    static int const    lowestGrade = 150;

    class GradeTooHighException: public std::exception {
      public:
        virtual const char* what(void) const throw();
    };

    class GradeTooLowException: public std::exception {
      public:
        virtual const char* what(void) const throw();
    };

  private:
    std::string const _name;
    int               _grade;
};

std::ostream& operator<<(std::ostream & os, Bureaucrat const* obj);

#endif

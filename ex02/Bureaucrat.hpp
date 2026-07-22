#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

# include "AForm.hpp"
// # include "ShrubberyCreationForm.hpp"

class Bureaucrat
{
public:
  Bureaucrat( );
  ~Bureaucrat( );
  Bureaucrat( const std::string &, int );
  Bureaucrat( const Bureaucrat& );
  Bureaucrat & operator=( Bureaucrat & );
  int getGrade( ) const;
  const std::string & getName( );
  void increamentGrade( );
  void decreamentGrade( );
  void signForm( AForm & );
  void executeForm( const AForm & ) const;

  class GradeTooHighException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Grade is higher than 1\n");
    }
  };

  class GradeTooLowException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Grade is less than 150\n");
    }
  };

private:
  const std::string m_name;
  int m_grade;
};

std::ostream & operator<<(std::ostream & , Bureaucrat & );

#endif

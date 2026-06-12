#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

# include "AForm.hpp"

class Bureaucrat
{
public:
  // Bureaucrat( );
  ~Bureaucrat( );
  Bureaucrat( const std::string &, int );
  Bureaucrat( const Bureaucrat& );
  Bureaucrat & operator=( Bureaucrat & );
  int _getGrade( ) const;
  const std::string & _getName( );
  void _increamentGrade( );
  void _decreamentGrade( );
  void _signForm( AForm & );

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
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
public:
  virtual ~AForm( );
  AForm( const AForm & );
  AForm( std::string , int , int );
  AForm & operator=( const AForm & );
  int _getSignGrade( );
  bool _getSignedFlag( );
  int _getExecutionGrade( );
  void _beSigned( Bureaucrat & );
  const std::string & _getName( );
  void _execute( Bureaucrat const & executor ) const;
  virtual void _executeAction( ) const = 0;

  class GradeTooHighException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Grade is higher than 1");
    }
  };

  class GradeTooLowException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Grade is lower than 150");
    }
  };

  class NotSigndException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("The form is not signed, cannot perform execution");
    }
  };

private:
  const std::string m_name;
  const int m_signGrade;
  const int m_executeGrade;
  bool  m_signedFlage;
};

std::ostream & operator<<( std::ostream &, AForm & );

#endif
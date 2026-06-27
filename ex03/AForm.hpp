#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
public:
  AForm();
  virtual ~AForm( );
  AForm( const AForm & );
  AForm( std::string , int , int );
  AForm & operator=( const AForm & );
  int _getSignGrade( ) const;
  bool _getSignedFlag( ) const;
  int _getExecutionGrade( ) const;
  std::string _getTarget( ) const;
  void _beSigned( Bureaucrat & );
  const std::string & _getName( ) const;
  void _execute( Bureaucrat const & executor ) const;
  virtual void _executeAction( ) const = 0;

  class GradeTooHighException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Grade is high ");
    }
  };

  class GradeTooLowException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Grade is low " );
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

  class FileCreationException: public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return ("Failed to create the file");
    }
  };

  class RobotomizationException: public std::exception
  {
  public:
	virtual const char* what() const throw()
	{
	  return ("robotomization failed");
	}
  };

protected:
  std::string m_target;

private:
  const std::string m_name;
  const int m_signGrade;
  const int m_executeGrade;
  bool  m_signedFlag;
};

std::ostream & operator<<( std::ostream &, AForm & );

#endif

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
public:
  ~Form( );
  Form( std::string , int , int );
  Form( const Form & );
  Form & operator=( const Form & );
  const std::string & getName( );
  int getSignGrade( );
  int getExecutionGrade( );
  bool getSignedFlag( );
  void beSigned( Bureaucrat & );
  // add a signForm() member function in the Bureaucrat class. 

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

private:
  const std::string m_name;
  const int m_signGrade;
  const int m_executeGrade;
  bool  m_signedFlage;
};

std::ostream & operator<<( std::ostream &, Form & );

#endif
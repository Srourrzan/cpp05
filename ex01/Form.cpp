#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( )
  : m_name(""),
    m_signGrade(150),
    m_executeGrade(150),
    m_signedFlag(false)
{}

Form::~Form( )
{}

Form::Form( std::string name, int signGrade, int executeGrade)
  : m_name(name),
    m_signGrade(signGrade),
    m_executeGrade(executeGrade),
    m_signedFlag(false)
{
  if (m_signGrade < 1 || m_executeGrade < 1)
    throw GradeTooHighException();
  else if (m_signGrade > 150 || m_executeGrade > 150)
    throw GradeTooLowException();
}

Form::Form( const Form & src)
  : m_name(src.m_name),
    m_signGrade(src.m_signGrade),
    m_executeGrade(src.m_executeGrade),
    m_signedFlag(src.m_signedFlag)
{}

Form & Form::operator=( const Form & rhs )
{
  if (this != &rhs)
  {
    m_signedFlag = rhs.m_signedFlag;
  }
  return (*this);
}

const std::string & Form::getName( )
{
  return (m_name);
}

int Form::getSignGrade( )
{
  return (m_signGrade);
}

int Form::getExecutionGrade( )
{
  return (m_executeGrade);
}

bool Form::getSignedFlag( )
{
  return (m_signedFlag);
}

void Form::beSigned( Bureaucrat & boss )
{
  if (boss.getGrade() <= m_signGrade)
    m_signedFlag = true;
  else
    throw GradeTooLowException();
}

std::ostream & operator<<( std::ostream & os, Form & rhs)
{
  os << "Form name: "
      << rhs.getName()
      << "\nsign minimum grade: "
      << rhs.getSignGrade()
      << "\nexecution minimum grade: "
      << rhs.getExecutionGrade()
      << "\nis it signed: "
      << rhs.getSignedFlag()
      << std::endl;
  
  return (os);
}

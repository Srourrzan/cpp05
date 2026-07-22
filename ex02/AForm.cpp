#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( )
  : m_name(""),
    m_signGrade(0),
    m_executeGrade(0),
    m_signedFlag(false)
{}

AForm::~AForm( )
{}

AForm::AForm( std::string name, int signGrade, int executeGrade)
  : m_name(name),
    m_signGrade(signGrade),
    m_executeGrade(executeGrade),
    m_signedFlag(false)
{
  if (m_signGrade < 1 || m_executeGrade < 1)
    throw (GradeTooHighException());
  else if (m_signGrade > 150 || m_executeGrade > 150)
    throw (GradeTooLowException());
}

AForm::AForm( const AForm & src)
  : m_name(src.m_name),
    m_signGrade(src.m_signGrade),
    m_executeGrade(src.m_executeGrade),
    m_signedFlag(src.m_signedFlag)
{}

AForm & AForm::operator=( const AForm & rhs )
{
  if (this != &rhs)
  {
    m_signedFlag = rhs.m_signedFlag;
  }
  return (*this);
}

const std::string & AForm::getName( ) const
{
  return (m_name);
}

int AForm::getSignGrade( ) const
{
  return (m_signGrade);
}

int AForm::getExecutionGrade( ) const
{
  return (m_executeGrade);
}

bool AForm::getSignedFlag( ) const
{
  return (m_signedFlag);
}

std::string AForm::getTarget( ) const
{
  return (m_target);
}

void AForm::beSigned( Bureaucrat & boss )
{
  std::cout << "Form sign grade: "
            << m_signGrade
            << "\nboss grade: "
            << boss.getGrade()
            << std::endl;
  if (boss.getGrade() <= m_signGrade)
    m_signedFlag = true;
  else
    throw (GradeTooLowException());
}

void AForm::executeAction( Bureaucrat const & executor ) const
{
  if (!m_signedFlag)
    throw (NotSigndException());
  if (executor.getGrade() > m_executeGrade) //check condition
    throw (GradeTooLowException());
  execute(executor);
}


std::ostream & operator<<( std::ostream & os, AForm & rhs)
{
  os << "AForm name: "
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

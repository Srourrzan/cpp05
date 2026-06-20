#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( )
  : m_name(""),
    m_signGrade(0),
    m_executeGrade(0),
    m_signedFlage(false)
{}

AForm::~AForm( )
{}

AForm::AForm( std::string name, int signGrade, int executeGrade)
  : m_name(name),
    m_signGrade(signGrade),
    m_executeGrade(executeGrade),
    m_signedFlage(false)
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
    m_signedFlage(src.m_signedFlage)
{}

AForm & AForm::operator=( const AForm & rhs )
{
  if (this != &rhs)
  {
    m_signedFlage = rhs.m_signedFlage;
  }
  return (*this);
}

const std::string & AForm::_getName( ) const
{
  return (m_name);
}

int AForm::_getSignGrade( ) const
{
  return (m_signGrade);
}

int AForm::_getExecutionGrade( ) const
{
  return (m_executeGrade);
}

bool AForm::_getSignedFlag( ) const
{
  return (m_signedFlage);
}

void AForm::_beSigned( Bureaucrat & boss )
{
  std::cout << "Form sign grade: "
            << m_signGrade
            << "\nboss grade: "
            << boss._getGrade()
            << std::endl;
  if (boss._getGrade() <= m_signGrade)
    m_signedFlage = true;
  else
    throw (GradeTooLowException());
}

void AForm::_execute( Bureaucrat const & executor ) const
{
  if (!m_signedFlage)
    throw (NotSigndException());
  if (executor._getGrade() > m_executeGrade) //check condition
    throw (GradeTooLowException());
  _executeAction();
}


std::ostream & operator<<( std::ostream & os, AForm & rhs)
{
  os << "AForm name: "
      << rhs._getName()
      << "\nsign minimum grade: "
      << rhs._getSignGrade()
      << "\nexecution minimum grade: "
      << rhs._getExecutionGrade()
      << "\nis it signed: "
      << rhs._getSignedFlag()
      << std::endl;
  
  return (os);
}

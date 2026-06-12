#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat( )
{}

Bureaucrat::Bureaucrat( const std::string & name, int grade)
  : m_name(name),
    m_grade(grade)
{
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src)
  : m_name(src.m_name),
    m_grade(src.m_grade)
{}

Bureaucrat & Bureaucrat::operator=( Bureaucrat & rhs)
{
  if (this != &rhs)
  {
    m_grade = rhs.m_grade;
  }
  return (*this);
}

const std::string & Bureaucrat::_getName()
{
  return (m_name);
}

int Bureaucrat::_getGrade( ) const
{
  return (m_grade);
}

void Bureaucrat::_increamentGrade()
{
  m_grade -= 1;
  if (m_grade < 1)
    throw GradeTooHighException();
}

void Bureaucrat::_decreamentGrade()
{
  m_grade += 1;
  if (m_grade > 150)
    throw GradeTooLowException();
}

void Bureaucrat::_signForm( AForm & form )
{
  try
  {
    form._beSigned(*this);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << m_name
            << " signed "
            << form._getName()
            << std::endl;
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & rhs)
{
  os  << rhs._getName()
      << ", bureaucrat grade "
      << rhs._getGrade()
      << ".";
  
  return (os);
}

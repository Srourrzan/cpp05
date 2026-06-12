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
    // m_name = rhs.m_name;
    m_grade = rhs.m_grade;
  }
  return (*this);
}

std::string & Bureaucrat::getName()
{
  return (m_name);
}

int Bureaucrat::getGrade( )
{
  return (m_grade);
}

void Bureaucrat::increamentGrade()
{
  m_grade -= 1;
  if (m_grade < 1)
    throw GradeTooHighException();
}

void Bureaucrat::decreamentGrade()
{
  m_grade += 1;
  if (m_grade > 150)
    throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & rhs)
{
  os  << rhs.getName()
      << ", bureaucrat grade "
      << rhs.getGrade()
      << ".";
  
  return (os);
}

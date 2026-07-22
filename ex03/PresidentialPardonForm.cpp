#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( )
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm( const std::string & target )
  : AForm("PresidentialPardonForm", 25, 5)
{
  m_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & rhs )
  : AForm("PresidentialPardonForm", 25, 5)
{
  m_target = rhs.m_target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & rhs )
{
  if (this != & rhs)
	m_target = rhs.m_target;
  return (*this);
}


void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
  (void)executor;
  std::cout << m_target
			<< "has been pardoned by Zaphod Beeblebrox"
			<< std::endl;
}

std::ostream & operator<<( std::ostream & os, const PresidentialPardonForm & rhs )
{
  os << "Presidential Pardon form {"
      << "target: "
      << rhs.getTarget()
      << " sign grade: "
      << rhs.getSignGrade()
      << " execution grade: "
      << rhs.getExecutionGrade()
      << "}";

  return (os);
}


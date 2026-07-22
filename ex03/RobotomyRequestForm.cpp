#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( )
{}

RobotomyRequestForm::~RobotomyRequestForm( )
{}

RobotomyRequestForm::RobotomyRequestForm( const std::string & target )
  : AForm("RobotomyRequestForm", 72, 45)
{
  m_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
  : AForm("RobotomyRequestForm", 72, 45)
{
  m_target = src.m_target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & rhs )
{
  if (this != &rhs)
	m_target = rhs.m_target;
  return (*this);
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
  (void)executor;
  std::cout << "Dnn Dnnnn Dnn Dnn\n"
			<< "Vrmmmmmmmmmmm, Vrmmmmmmm.\n"
			<< std::endl;
  if ((std::rand() % 2) == 0)
	{
	  std::cout << m_target
				<< " has been robotomized"
				<< std::endl;
	}
  else
	{
	  throw (RobotomizationException());
	}
  
}

std::ostream & operator<<( std::ostream & os, const RobotomyRequestForm & rhs )
{
    os << "Robotomy form {"
      << "target: "
      << rhs.getTarget()
      << " sign grade: "
      << rhs.getSignGrade()
      << " execution grade: "
      << rhs.getExecutionGrade()
      << "}";

  return (os);
}

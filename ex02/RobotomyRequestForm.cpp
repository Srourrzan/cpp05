#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm( )
{}

RobotomyRequestForm::RobotomyRequestForm( const std::string & target )
  : AForm("RobotomyRequestForm", 72, 45),
	m_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
  : AForm("RobotomyRequestForm", 72, 45),
	m_target(src.m_target)
{}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & rhs )
{
  if (this != &rhs)
	m_target = rhs.m_target;
  return (*this);
}

std::string RobotomyRequestForm::_getTarget( ) const
{
  return (m_target);
}

void RobotomyRequestForm::_executeAction( ) const
{
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
	  std::cout << "robotomization failed"
				<< std::endl;
	}
  
}

std::ostream & operator<<( std::ostream & os, const RobotomyRequestForm & rhs )
{
    os << "Robotomy form {"
      << "target: "
      << rhs._getTarget()
      << " sign grade: "
      << rhs._getSignGrade()
      << " execution grade: "
      << rhs._getExecutionGrade()
      << "}";

  return (os);
}

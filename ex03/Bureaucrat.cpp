#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( )
  : m_name (""),
    m_grade(150)
{}

Bureaucrat::~Bureaucrat( )
{}

Bureaucrat::Bureaucrat( const std::string & name, int grade)
  : m_name(name),
    m_grade(grade)
{
  if (grade < 1)
    throw (GradeTooHighException());
  else if (grade > 150)
    throw (GradeTooLowException());
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

const std::string & Bureaucrat::getName()
{
	return (m_name);
}

int Bureaucrat::getGrade( ) const
{
	return (m_grade);
}

void Bureaucrat::increamentGrade()
{
	m_grade -= 1;
	if (m_grade < 1)
		throw (GradeTooHighException());
}

void Bureaucrat::decreamentGrade()
{
	m_grade += 1;
	if (m_grade > 150)
		throw (GradeTooLowException());
}

void Bureaucrat::signForm( AForm & form )
{
	try
  {
    form.beSigned(*this);
    std::cout << m_name
            << " signed "
            << form.getName()
            << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

void Bureaucrat::executeForm( const AForm & form ) const
{
	try
	{
		form.executeAction(*this);
		std::cout << this->m_name
				  << " executed "
				  << form.getName()
				  << std::endl;
	}
	catch(const AForm::NotSigndException & e)
	{
		std::cerr << e.what() 
							<< std::endl;
  }
  catch(const AForm::GradeTooLowException & e)
  {
    std::cerr << m_name
			  << " "
			  << e.what()
			  << m_grade
			  << " for the form with execution grade of "
			  << form.getExecutionGrade()
              << std::endl;
  }
  catch(const AForm::FileCreationException & e)
  {
    std::cerr << e.what()
              << std::endl;
  }
  catch (const AForm::RobotomizationException & e)
	{
	  std::cerr << e.what()
				<< std::endl;
	}
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & rhs)
{
  os  << rhs.getName()
      << ", bureaucrat grade "
      << rhs.getGrade()
      << ".";
  
  return (os);
}

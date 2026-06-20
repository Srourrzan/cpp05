#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>


class RobotomyRequestForm: public AForm
{
public:
  virtual ~RobotomyRequestForm( );
  RobotomyRequestForm( const std::string & );
  RobotomyRequestForm( const RobotomyRequestForm & );
  RobotomyRequestForm & operator=( const RobotomyRequestForm & );

  std::string _getTarget( ) const;
  virtual void _executeAction( ) const;

private:
  std::string m_target;
};

std::ostream & operator<<( std::ostream &, const RobotomyRequestForm & );

#endif

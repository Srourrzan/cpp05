#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>


class RobotomyRequestForm: public AForm
{
public:
  RobotomyRequestForm( );
  virtual ~RobotomyRequestForm( );
  RobotomyRequestForm( const std::string & );
  RobotomyRequestForm( const RobotomyRequestForm & );
  RobotomyRequestForm & operator=( const RobotomyRequestForm & );
  
  virtual void _executeAction( ) const;

private:
  
};

std::ostream & operator<<( std::ostream &, const RobotomyRequestForm & );

#endif

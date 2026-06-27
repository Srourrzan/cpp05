#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
  PresidentialPardonForm( );
  virtual ~PresidentialPardonForm( );
  PresidentialPardonForm( const std::string & );
  PresidentialPardonForm( const PresidentialPardonForm & );
  PresidentialPardonForm & operator=( const PresidentialPardonForm & );

  virtual void _executeAction( ) const;

private:
  
};

std::ostream & operator<<( std::ostream &, const PresidentialPardonForm & );

#endif

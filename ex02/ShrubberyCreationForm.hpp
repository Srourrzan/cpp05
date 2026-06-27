#ifndef ShrubberyCreationForm_hpp
# define ShrubberyCreationForm_hpp

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
public:
  ShrubberyCreationForm( );
  virtual ~ShrubberyCreationForm( );
  ShrubberyCreationForm( const std::string & );
  ShrubberyCreationForm( const ShrubberyCreationForm & );
  ShrubberyCreationForm & operator=( const ShrubberyCreationForm & );

  virtual void _executeAction( ) const;

private:
  
};

std::ostream & operator<<( std::ostream &, const ShrubberyCreationForm & );

#endif

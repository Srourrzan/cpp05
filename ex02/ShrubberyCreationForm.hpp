#ifndef ShrubberyCreationForm_hpp
# define ShrubberyCreationForm_hpp

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
public:
  ~ShrubberyCreationForm( );
  ShrubberyCreationForm( const std::string & );
  ShrubberyCreationForm( const ShrubberyCreationForm & );
  ShrubberyCreationForm & operator=( const ShrubberyCreationForm & );

  std::string _getTarget( ) const;
  void _executeAction( ) const;


private:
  std::string m_target;
};

std::ostream & operator<<( std::ostream &, const ShrubberyCreationForm & );

#endif
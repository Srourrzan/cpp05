#ifndef ShrubberyCreationForm_hpp
# define ShrubberyCreationForm_hpp

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
  ~ShrubberyCreationForm( );
  ShrubberyCreationForm( std::string & );
  ShrubberyCreationForm( const ShrubberyCreationForm & );
  ShrubberyCreationForm & operator<<( const ShrubberyCreationForm & );
  

private:
  std::string m_target;
  const int m_signGrade = 145;
  const int m_executionGrade = 137;
};

std::ostream & operator<<( std::ostream &, const ShrubberyCreationForm & );

#endif
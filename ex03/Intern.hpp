#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern
{
public:
  Intern();
  ~Intern();
  Intern( const Intern & );
  Intern & operator=( const Intern & );

  AForm * makeForm( const std::string &, const std::string & );

private:
  
};

#endif
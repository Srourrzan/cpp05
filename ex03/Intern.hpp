#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
  Intern( );
  ~Intern( );
  Intern( const Intern & );
  Intern & operator=( const Intern & );

  AForm* makeForm(const std::string &name, const std::string &target);

private:
  AForm * _createShrubbery( const std::string & );
  AForm * _createRobotomy( const std::string & );
  AForm * _createPresidential( const std::string & );
  struct FromInfoStruct {
    std::string name;
    AForm* (Intern::*creator)( const std::string & );
  };
  static const FromInfoStruct fromTypes[];
  static const size_t fromCount;
};

#endif
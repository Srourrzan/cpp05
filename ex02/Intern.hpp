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
  static AForm* createShrubbery(const std::string &target);
  static AForm* createRobotomy(const std::string &target);
  static AForm* createPresidential(const std::string &target);

  struct FormInfo {
      std::string name;
      AForm* (*creator)(const std::string &);
  };

  static const FormInfo formTypes[];
  static const size_t formCount;
};

#endif
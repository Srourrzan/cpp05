#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm * Intern::createShrubbery( const std::string & target )
{
  return new ShrubberyCreationForm(target);
}

AForm * Intern::createRobotomy( const std::string & target )
{
  return new RobotomyRequestForm(target);
}

AForm * Intern::createPresidential( const std::string & target )
{
  return new PresidentialPardonForm(target);
}

const Intern::FromInfoStruct Intern::fromTypes[] = {
  {"shrubbery creation", &Intern::createShrubbery},
  {"robotomy request", &Intern::createRobotomy},
  {"presidential pardon", &Intern::createPresidential}
};

const size_t Intern::fromCount = sizeof(Intern::fromTypes) / sizeof(Intern::fromTypes[0]);

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    for (size_t i = 0; i < fromCount; ++i) {
        if (fromTypes[i].name == name) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*fromTypes[i].creator)(target);
        }
    }
    std::cerr << "Intern: Form type '" << name << "' does not exist." << std::endl;
    return NULL;
}
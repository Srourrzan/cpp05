#include "Intern.hpp"

Intern::Intern() 
{}

Intern::~Intern() 
{}

Intern::Intern(const Intern &other) 
{ 
  (void)other;
}

Intern &Intern::operator=(const Intern &other) 
{ 
  (void)other; 
  return *this; 
}

const Intern::FormInfo Intern::formTypes[] = {
  {"shrubbery creation", &Intern::createShrubbery},
  {"robotomy request", &Intern::createRobotomy},
  {"presidential pardon", &Intern::createPresidential}
};

// Alternative correct line:
const size_t Intern::formCount = sizeof(Intern::formTypes) / sizeof(Intern::FormInfo);

AForm* Intern::createShrubbery(const std::string &target) {
  return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string &target) {
  return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string &target) {
  return (new PresidentialPardonForm(target));
}


AForm* Intern::makeForm(const std::string &name, const std::string &target) {
  for (size_t i = 0; i < formCount; ++i) {
      if (formTypes[i].name == name) {
          std::cout << "Intern creates " << name << std::endl;
          return formTypes[i].creator(target);
      }
  }
  std::cerr << "Intern: Form type '" << name << "' does not exist." << std::endl;
  return NULL;
}
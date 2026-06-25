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

AForm * Intern::_createShrubbery( const std::string & target )
{
  return new ShrubberyCreationForm(target);
}

AForm * Intern::_createRobotomy( const std::string & target )
{
  return new RobotomyRequestForm(target);
}

const Intern::FromInfoStruct Intern::fromTypes[] = {
  {"shrubbery creation", &Intern::_createShrubbery},
  {"robotomy request", &Intern::_createRobotomy},
  {"presidential pardon", &Intern::_createPresidential}
};

// // Fix: Divide by sizeof(element), not the whole array
// const size_t Intern::formCount = sizeof(Intern::formTypes) / sizeof(Intern::formTypes);


// AForm* Intern::createRobotomy(const std::string &target) {
//     return new RobotomyRequestForm(target);
// }

// AForm* Intern::createPresidential(const std::string &target) {
//     // Fix: Remove C++11 initializer list syntax
//     return new PresidentialPardonForm(target);
// }

// AForm* Intern::makeForm(const std::string &name, const std::string &target) {
//     for (size_t i = 0; i < formCount; ++i) {
//         if (formTypes[i].name == name) {
//             std::cout << "Intern creates " << name << std::endl;
//             return formTypes[i].creator(target);
//         }
//     }
//     std::cerr << "Intern: Form type '" << name << "' does not exist." << std::endl;
//     return NULL;
// }
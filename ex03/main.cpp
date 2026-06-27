#include <ctime>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
  std::srand((unsigned)std::time(NULL));
  try
  {
    Bureaucrat Tom("Tom", 45);
    ShrubberyCreationForm Shrub("house");
    std::cout << Tom
              << "\n"
              << Shrub
              << std::endl;
    Tom._signForm(Shrub);
    Tom._executeForm(Shrub);

    Bureaucrat Jerry("Jerry", 149);
    ShrubberyCreationForm schoolShrub("School");
    std::cout << Jerry
              << "\n"
              << schoolShrub
              << std::endl;
    Jerry._signForm(schoolShrub);
    Jerry._executeForm(schoolShrub);

    Bureaucrat John("John", 140);
    ShrubberyCreationForm parkShrub("Park");
    std::cout << John
              << "\n"
              << parkShrub
              << std::endl;
    John._signForm(parkShrub);
    John._executeForm(parkShrub);

	RobotomyRequestForm Robo("test");
	Tom._signForm(Robo);
	Tom._executeForm(Robo);
	RobotomyRequestForm Car("Car");
	Jerry._signForm(Car);
	Jerry._executeForm(Car);

	PresidentialPardonForm family1("family1");
	John._signForm(family1);
	John._executeForm(family1);

	PresidentialPardonForm family2("family2");
	Jerry._signForm(family2);
	Jerry._executeForm(family2);
    {
      Intern someRandomIntern;
      AForm* rrf;
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return (1);
  }
  return (0);
}

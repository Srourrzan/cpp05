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
    Tom.signForm(Shrub);
    Tom.executeForm(Shrub);

    Bureaucrat Jerry("Jerry", 149);
    ShrubberyCreationForm schoolShrub("School");
    std::cout << Jerry
              << "\n"
              << schoolShrub
              << std::endl;
    Jerry.signForm(schoolShrub);
    Jerry.executeForm(schoolShrub);

    Bureaucrat John("John", 140);
    ShrubberyCreationForm parkShrub("Park");
    std::cout << John
              << "\n"
              << parkShrub
              << std::endl;
    John.signForm(parkShrub);
    John.executeForm(parkShrub);

	RobotomyRequestForm Robo("test");
	Tom.signForm(Robo);
	Tom.executeForm(Robo);
	RobotomyRequestForm Car("Car");
	Jerry.signForm(Car);
	Jerry.executeForm(Car);

	PresidentialPardonForm family1("family1");
	John.signForm(family1);
	John.executeForm(family1);

	PresidentialPardonForm family2("family2");
	Jerry.signForm(family2);
	Jerry.executeForm(family2);
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

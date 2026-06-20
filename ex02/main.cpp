#include <ctime>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
  std::srand((unsigned)std::time(NULL));
  try
  {
    Bureaucrat Tom("Tom", 45);
    ShrubberyCreationForm Shrub("house");
    LOG_INFO();
    std::cout << Tom
              << "\n"
              << Shrub
              << std::endl;
    Tom._signForm(Shrub);
    Tom._executForm(Shrub);

    Bureaucrat Jerry("Jerry", 149);
    ShrubberyCreationForm schoolShrub("School");
    LOG_INFO();
    std::cout << Jerry
              << "\n"
              << schoolShrub
              << std::endl;
    Jerry._signForm(schoolShrub);
    Jerry._executForm(schoolShrub);

    Bureaucrat John("John", 140);
    ShrubberyCreationForm parkShrub("Park");
    LOG_INFO();
    std::cout << John
              << "\n"
              << parkShrub
              << std::endl;
    John._signForm(parkShrub);
    John._executForm(parkShrub);

	RobotomyRequestForm Robo("test");
	Tom._signForm(Robo);
	Tom._executForm(Robo);
	RobotomyRequestForm Car("Car");
	Jerry._signForm(Car);
	Jerry._executForm(Car);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return (1);
  }
  return (0);
}

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  try
  {
    try
    {
      Bureaucrat Tom("Tom", 160);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    Bureaucrat Jerry("Jerry", 5);
    std::cout << Jerry
              << std::endl;
    std::cout << "Increase Jerry's grade by 1"
              << std::endl;
    Jerry.increamentGrade();
    std::cout << Jerry.getName()
              << " grade: "
              << Jerry.getGrade()
              << std::endl;

    Form highForm("F00", 5, 1);
    Form midForm("F01", 75, 50);
    std::cout << "Make "
              << Jerry.getName()
              << " sign a very important form: \n"
              << highForm
              << std::endl;
    Jerry.signForm(highForm);
    std::cout << highForm.getName()
              << " got signed "
              << highForm.getSignedFlag()
              << std::endl;

    Bureaucrat Tod("Tod", 150);
    std::cout << "A new bureaucrat got joined, named: "
              << Tod.getName()
              << std::endl;
    std::cout << "Make "
              << Tod.getName()
              << " sign mid important form "
              << midForm
              << std::endl;
    std::cout << midForm.getName()
              << " got signed "
              << midForm.getSignedFlag()
              << std::endl;
    
    std::cout << Jerry.getName()
              << " got to retire"
              << std::endl;
    Jerry.increamentGrade();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return (1);
  }
  return (0);
}
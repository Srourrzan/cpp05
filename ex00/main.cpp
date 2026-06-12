# include "Bureaucrat.hpp"

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
    Bureaucrat Jerry("Jerry", 2);
    std::cout << Jerry
              << std::endl;
    std::cout << "Increase Jerry's grade by 1"
              << std::endl;
    Jerry.increamentGrade();
    std::cout << "Jerry's grade: "
              << Jerry.getGrade();
    Bureaucrat Tod("Tod", 150);
    std::cout << "A new bureaucrat got joined, named: "
              << Tod.getName()
              << std::endl;
    std::cout << "Jerry got to retire"
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
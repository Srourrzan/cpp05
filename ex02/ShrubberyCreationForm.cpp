#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( )
{}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target )
  : AForm("ShrubberyCreationForm", 145, 137),
    m_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
  : AForm("ShrubberyCreationForm", 145, 137),
    m_target(src.m_target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs )
{
  if (this != &rhs)
    m_target = rhs.m_target;
  return (*this);
}

std::string ShrubberyCreationForm::_getTarget( ) const
{
  return (m_target);
}

void ShrubberyCreationForm::_executeAction( ) const
{
  std::string fileName(m_target + "_shrubbery");
  std::ofstream outf(fileName.c_str());
  if (!outf)
  {
    throw (FileCreationException());
  }
  outf  << "             .o00o               \n"
        << "           o000000oo             \n"
        << "          00000000000o           \n"
        << "         00000000000000          \n"
        << "      oooooo  00000000  o88o     \n"
        << "   oo0000000oo  ```''  888888    \n"
        << " OOOOOOOOOOOO'.qQQQQq. `8888'    \n"
        << "oOOOOOOOOOO'.QQQQQQQQQQ/.88'     \n"
        << "OOOOOOOOOO'.QQQQQQQQQQ/ /q       \n"
        << " OOOOOOOOO QQQQQQQQQQ/ /QQ       \n"
        << "   OOOOOOOOO `QQQQQQ/ /QQ'       \n"
        << "     OO:F_P:O `QQQ/  /Q'         \n"
        << "        \\. \\ |  // |            \n"
        << "        d\\ \\\\\\|_////             \n"
        << "        qP| \\\\ _' `|Ob           \n"
        << "           \\\\  / \\  \\Op           \n"
        << "           |  | O| |             \n"
        << "   _       /\\. \\_/ /\\            \n"
        << "    `---__/|_\\\\   //|  __        \n"
        << "          `-'  `-'`-'-'          \n"
        << std::endl;

  outf.close();
}

std::ostream & operator<<( std::ostream & os, const ShrubberyCreationForm & rhs )
{
  os << "Shrubbery form {"
      << "target: "
      << rhs._getTarget()
      << " sign grade: "
      << rhs._getSignGrade()
      << " execution grade: "
      << rhs._getExecutionGrade()
      << "}";

  return (os);
}
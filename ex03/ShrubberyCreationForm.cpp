#include "ShrubberyCreationForm.hpp"

/*=============== CONSTRUCTOR ===============*/
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("SCF", 145, 137) {
	_target	= "Unknown";
	std::cout << "Shrubbery Creation Form " + getName() + " constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("SCF", 145, 137) {
	_target	= target;
	std::cout << "Shrubbery Creation Form " + getName() + " constructed." << std::endl;
}
/*=============== DESTRUCTOR ===============*/

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) : AForm( copy ) {
	*this = copy;
	std::cout << "SCF " + getName() + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign ) {
	this->_target = assign._target;
	return (*this); 
}

/*=============== PUBLIC  ===============*/

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {

	std::cout << "Execution status granted by " << executor.getName() << std::endl;
	std::cout << CYAN << "Shrubbery Created!" << RESET << std::endl;
	std::ofstream shrub(_target + "_shrubbery");
	shrub << "//          &&& &&  & &&" << std::endl;
	shrub << "//      && &\\/&\\|& ()|/ @, &&" << std::endl;
	shrub << "//      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	shrub << "//   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	shrub << "//  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	shrub << "//&&   && & &| &| /& & % ()& /&&" << std::endl;
	shrub << "// ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	shrub << "//     &&     \\|||" << std::endl;
	shrub << "//             |||" << std::endl;
	shrub << "//             |||" << std::endl;
	shrub << "//             |||" << std::endl;
	shrub << "//       , -=-~  .-^- _" << std::endl;
	shrub.close();
}

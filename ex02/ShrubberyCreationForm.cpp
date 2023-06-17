#include "ShrubberyCreationForm.hpp"

/*=============== CONSTRUCTOR ===============*/

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("SCF", 145, 137) {
	_target	= target;
	std::cout << "SCF Form " + getName() + " constructed." << std::endl;
}
/*=============== DESTRUCTOR ===============*/

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) : AForm( copy ) {
	*this = copy;
	std::cout << "SCF Form " + getName() + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign ) {
	this->_target = assign._target;
	return (*this); 
}

/*=============== PUBLIC  ===============*/

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	try {
		if (getStatus() && !getExecStatus() && executor.getGrade() <= getExec()) {
			createShrub();
			b.executeForm(this);
		}
		else if (!getStatus())
			throw ShrubberyCreationForm::UnsignedForm();
		else if (getExec())
			throw ShrubberyCreationForm::FormAlreadyExecuted();
		else if (executor.getGrade() > getExec())
			throw ShrubberyCreationForm::ExecGradeLow():
	}
	catch (ShrubberyCreationForm::UnsignedForm &except) {
		std::cout << except.what() << std::endl;
	}
	catch (ShrubberyCreationForm::ExecGradeLow &except) {
		std::cout << except.what() << " Required grade to execute this form is ("
				<< getExec() << ")\033[0m"
				<< std::endl;
	}
	catch (ShrubberyCreationForm::FormAlreadyExecuted &except ) {
		std::cout << except.what() << std::endl;
	}
}

/*=============== 	EXCEPTION  ===============*/

const char* ShrubberyCreationForm::UnsignedForm::what( void ) const throw() {
	return ("\033[31mSCF status unsigned.\033[0m");
}

const char* ShrubberyCreationForm::ExecGradeLow::what( void ) const throw() {
	return ("\033[31mExecution Grade too low.");
}

const char* ShrubberyCreationForm::UnsignedForm::what( void ) const throw() {
	return ("\033[31mThis form has already been executed.\033[0m");
}
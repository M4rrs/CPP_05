#include "Intern.hpp"

int main( void ) {
	// I hate making test files
	std::cout << "\033[35;1m\n[ CONSTRUCTING INTERNS + COPY ]\033[0m" << std::endl;

	Intern *intern1 = new Intern();
	Intern *intern2 = new Intern();
	std::cout << std::endl;

	std::cout << "Copy Intern: ";
	Intern *intern3 = new Intern(*intern1);

	std::cout << "\033[35;1m\n[ MAKING FORMS ]\033[0m" << std::endl;

	AForm *SCF = intern1->makeForm("shrubbery creation", "DECOY1");
	std::cout << std::endl;
	
	AForm *RRF = intern2->makeForm("robotomy request", "DECOY2");
	std::cout << std::endl;

	std::cout << "Made by Copy Intern: ";
	AForm *PPF = intern1->makeForm("presidential pardon", "DECOY3");
	std::cout << std::endl;

	std::cout << "\033[35;1m\n[ ANNOUNCING FORMS ]\033[0m" << std::endl;
	std::cout << SCF;
	std::cout << RRF;
	std::cout << PPF;

	std::cout << "\033[35;1m\n[ DESTRUCTING ]\033[0m" << std::endl;
	delete intern1;
	delete intern2;
	delete intern3;
	std::cout << std::endl;

	delete SCF;
	delete RRF;
	delete PPF;
}
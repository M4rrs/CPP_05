#include "Bureaucrat.hpp"

int main( void ) {

	std::cout << "\033[32;1m\n[  CONSTRUCTING BUREAUCRATS  ]\033[0m" << std::endl;
	Bureaucrat *a1 = new Bureaucrat();
	Bureaucrat *a2 = new Bureaucrat(5);
	Bureaucrat *a3 = new Bureaucrat("Tim", 1);
	std::cout << std::endl;

	std::cout << a1;
	std::cout << a2;
	std::cout << a3;

	std::cout << "\033[32;1m\n[  HIGH/LOW INSTANTIATION  ]\033[0m" << std::endl;
	Bureaucrat *b1 = new Bureaucrat("HIGH", 0);
	Bureaucrat *b2 = new Bureaucrat("LOW", 151);
	Bureaucrat *b3 = new Bureaucrat("MAX", 1);
	Bureaucrat *b4 = new Bureaucrat("MIN", 150);
	std::cout << std::endl;

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;
	std::cout << std::endl;

	delete b1;
	delete b2;
	delete b3;
	delete b4;

	std::cout << "\033[32;1m\n[  PROMOTION AND DEMOTION  ]\033[0m" << std::endl;
	a1->promote(1);
	a2->promote(2);
	a3->promote(1);
	std::cout << std::endl;

	a1->demote(1);
	a2->demote(147);
	a3->demote(150);

	std::cout << "\033[32;1m\n[  COPIES  ]\033[0m" << std::endl;
	Bureaucrat *c = new Bureaucrat(*a3);
	std::cout << std::endl;

	std::cout << a3;
	std::cout << c;
	std::cout << std::endl;

	a3->promote(5);

	std::cout << a3;
	std::cout << c;
	std::cout << std::endl;
	
	c->promote(120);

	std::cout << a3;
	std::cout << c;
	std::cout << std::endl;
	
	delete c;

	std::cout << "\n\033[32;1m[  DESTRUCTING  ]\033[0m" << std::endl;
	delete a1;
	delete a2;
	delete a3;
}
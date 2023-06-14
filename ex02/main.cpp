#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

	//default sign grade 75
	std::cout << "\033[35;1m\n[ GENERAL FORM TESTS ]\033[0m" << std::endl;

	Form *f1 = new Form();
	Form *f2 = new Form(30, 5);
	Form *f3 = new Form("Contract", 50, 10);
	std::cout << std::endl;

	std::cout << f1;
	std::cout << f2;
	std::cout << f3;

	std::cout << "\033[35m\n---------testing form grades--------\033[0m" << std::endl;
	Form *f4 = new Form(0, 5);
	Form *f5 = new Form(151, 5);
	Form *f6 = new Form(10, -1);
	Form *f7 = new Form(10, 155);
	std::cout << std::endl;

	std::cout << f4;
	std::cout << f5;
	std::cout << f6;
	std::cout << f7;
	std::cout << std::endl;

	delete f4;
	delete f5;
	delete f6;
	delete f7;

	std::cout << "\033[35;1m\n[ BUREAUCRAT + FORM TESTS ]\033[0m" << std::endl;

	Bureaucrat *b1 = new Bureaucrat("Bee", 100);
	Bureaucrat *b2 = new Bureaucrat("Boo", 100);
	Bureaucrat *b3 = new Bureaucrat("Baa", 100);
	std::cout << std::endl;

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << std::endl;

	f1->beSigned(b1);
	f1->beSigned(b2);
	f1->beSigned(b3);
	std::cout << std::endl;

	std::cout << "\033[35m\n---------B1 signing (grade 75)--------\033[0m" << std::endl;
	b1->promote(25);
	std::cout << std::endl;

	f1->beSigned(b1);
	f2->beSigned(b1);
	f3->beSigned(b1);
	std::cout << std::endl;

	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << std::endl;

	std::cout << "\033[35m\n---------B2 signing (grade 50)--------\033[0m" << std::endl;
	b2->promote(50);
	std::cout << std::endl;

	f2->beSigned(b2);
	f3->beSigned(b2);
	std::cout << std::endl;

	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << std::endl;

	std::cout << "\033[35m\n---------B3 signing (grade 30)--------\033[0m" << std::endl;
	b3->promote(50);
	std::cout << std::endl;

	f2->beSigned(b3);
	std::cout << std::endl;

	b3->promote(25);
	std::cout << std::endl;

	f2->beSigned(b3);
	std::cout << std::endl;

	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << std::endl;

	std::cout << "\033[35m\n---------Testing already signed forms (optional)--------\033[0m" << std::endl;
	f1->beSigned(b3);
	f2->beSigned(b2);
	f3->beSigned(b1);
	std::cout << std::endl;

	delete f1;
	delete f2;
	delete f3;
	std::cout << std::endl;

	std::cout << "\033[35m\n---------Form Copies--------\033[0m" << std::endl;
	{
	Form *f1 = new Form();
	Form *f2 = new Form(10, 10);
	Form *f3 = new Form("This Form", 10, 10);
	std::cout << std::endl;

	Form *c1 = new Form(*f1);
	Form *c2 = new Form(*f2);
	Form *c3 = new Form(*f3);
	std::cout << std::endl;

	std::cout << "\033[35m\n( form 1 + copy 1 )\033[0m" << std::endl;
	std::cout << f1;
	std::cout << c1;

	std::cout << "\033[35m\n( form 2 + copy 2 )\033[0m" << std::endl;
	std::cout << f2;
	std::cout << c2;

	std::cout << "\033[35m\n( form 3 + copy 3 )\033[0m" << std::endl;
	std::cout << f3;
	std::cout << c3;
	std::cout << std::endl;

	std::cout << "\033[35m\n---------Sign Copies--------\033[0m" << std::endl;
	Bureaucrat *p1 = new Bureaucrat("Po", 75);
	Bureaucrat *p2 = new Bureaucrat("Pi", 10);
	Bureaucrat *p3 = new Bureaucrat("Pa", 10);
	std::cout << std::endl;


	std::cout << "\033[35m\n( form 1 + copy 1 )\033[0m" << std::endl;
	c1->beSigned(p1);
	std::cout << f1;
	std::cout << c1;

	
	std::cout << "\033[35m\n( form 2 + copy 3 )\033[0m" << std::endl;
	f2->beSigned(p2);
	std::cout << f2;
	std::cout << c2;


	std::cout << "\033[35m\n( form 3 + copy 3 )\033[0m" << std::endl;
	c3->beSigned(p3);
	std::cout << f3;
	std::cout << c3;

	std::cout << "\033[35m\n( b3 trying signed c2 + unsigned f2 )\033[0m" << std::endl;
	c2->beSigned(p3);
	f2->beSigned(p3);

	std::cout << std::endl;
	delete f1;
	delete f2;
	delete f3;
	delete c1;
	delete c2;
	delete c3;
	delete p1;
	delete p2;
	delete p3;
	std::cout << std::endl;
	}

	std::cout << "\033[35;1m\n[ DESTRUCTING ]\033[0m" << std::endl;
	delete b1;
	delete b2;
	delete b3;
}
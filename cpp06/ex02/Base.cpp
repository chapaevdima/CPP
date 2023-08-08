#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base *generate(void)
{
	Base *p;

	int num = std::rand();
	
	if (num % 3 == 0)
	{
		p = new A();
		std::cout << "A object generated" << std::endl;
	}
	else if (num % 3 == 1)
	{
		p = new B();
		std::cout << "B object generated" << std::endl;
	}
	else
	{
		p = new C();
		std::cout << "C object generated" << std::endl;
	}

	return p;
}

void identify(Base *p)
{
	A *a_ptr = dynamic_cast<A*>(p);
	B *b_ptr = dynamic_cast<B*>(p);
	C *c_ptr = dynamic_cast<C*>(p);

	if (a_ptr != 0)
		std::cout << "this is an object A" << std::endl;
	else if (b_ptr != 0)
		std::cout << "this is an object B" << std::endl;
	else if (c_ptr != 0)
		std::cout << "this is an object C" << std::endl;
	else
		std::cout << "something went wrong" << std::endl;
}

void identify(Base& p)
{
	bool flag = false;

	try
	{
		A &a_ref = dynamic_cast<A&>(p);
		flag = true;
		std::cout << &a_ref << " is a reference A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		B &b_ref = dynamic_cast<B&>(p);
		flag = true;
		std::cout << &b_ref << " is a reference B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C &c_ref = dynamic_cast<C&>(p);
		flag = true;
		std::cout << &c_ref << " is a reference C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	if (flag == false)
		std::cout << "something went wrong" << std::endl;
}
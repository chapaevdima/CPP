#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main(void)
{
	std::srand(std::time(0));
	for (int i = 0; i < 15; i++)
	{
		Base *p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl << std::endl;
		delete p;
	}
	return 0;
}